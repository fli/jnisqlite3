package rete.sql;

public final class Sqlite3 implements AutoCloseable {
	public static final int OPEN_READONLY = 0x1;
	public static final int OPEN_READWRITE = 0x2;
	public static final int OPEN_CREATE = 0x4;
	
	private final long DB;
	private boolean closed;
	
	private static final class ResultCode {
		private static final int OK = 0;
		private static final int ERROR = 1;
		private static final int BUSY = 5;
		private static final int MISUSE = 21;
		private static final int ROW = 100;
		private static final int DONE = 101;
	}
	
	private static final class Native {
		private static native int open(String filename, long[] ppDb, int flags, String zVfs);
		private static native int prepare(long db, String zSql, int nByte, long[] ppStmt);
		private static native int bind(long pStmt, int i, int val);
		private static native int bind(long pStmt, int i, long val);
		private static native int bind(long pStmt, int i, double val);
		private static native int bind(long pStmt, int i, String val);
		private static native int step(long pStmt);
		private static native int columnInt(long pStmt, int iCol);
		private static native long columnLong(long pStmt, int iCol);
		private static native double columnDouble(long pStmt, int iCol);
		private static native String columnString(long pStmt, int iCol);
		private static native int _finalize(long pStmt); // non-underscore finalize is taken by Object
		private static native int close(long pDb);
		private static native int reset(long pStmt);
		private static native String errstr(int errcode);
	}
	
	public Sqlite3(String filename, int flags, String vfs) throws Exception {
		long[] ppDb = new long[1];
		int rescode = Native.open(filename, ppDb, flags, vfs);
		if (rescode == ResultCode.OK) {
			DB = ppDb[0];
		} else {
			throw new Exception(Native.errstr(rescode));
		}
	}
	public Sqlite3(String filename, int flags) throws Exception {
		this(filename, flags, null);
	}
	public Sqlite3(String filename) throws Exception {
		this(filename, OPEN_READWRITE | OPEN_CREATE, null);
	}
	
	public Statement prepare(String sql) throws Exception {
		long[] ppStmt = new long[1];
		int rescode = Native.prepare(DB, sql, sql.length() + 1, ppStmt);
		if (rescode == ResultCode.OK) {
			return new Statement(ppStmt[0]);
		} else {
			throw new Exception(Native.errstr(rescode));
		}
	}
	
	@Override
	public void close() {
		if (!closed) {
			Native.close(DB);
			closed = true;
		}
	}
	
	public final class Statement implements AutoCloseable {
		private final long STMT;
		private boolean closed;
		
		private Statement(long ppStmt) {
			STMT = ppStmt;
		}
		
		public Statement bind(int i, int val) throws Exception {
			int rescode = Native.bind(STMT, i, val);
			if (rescode == ResultCode.OK) {
				return this;
			} else {
				throw new Exception(Native.errstr(rescode));
			}
		}
		
		public Statement bind(int i, long val) throws Exception {
			int rescode = Native.bind(STMT, i, val);
			if (rescode == ResultCode.OK) {
				return this;
			} else {
				throw new Exception(Native.errstr(rescode));
			}
		}
		
		public Statement bind(int i, double val) throws Exception {
			int rescode = Native.bind(STMT, i, val);
			if (rescode == ResultCode.OK) {
				return this;
			} else {
				throw new Exception(Native.errstr(rescode));
			}
		}
		
		public Statement bind(int i, String val) throws Exception {
			int rescode = Native.bind(STMT, i, val);
			if (rescode == ResultCode.OK) {
				return this;
			} else {
				throw new Exception(Native.errstr(rescode));
			}
		}
		
		public boolean step() throws Exception {
			int rescode = Native.step(STMT);
			switch (rescode) {
				case ResultCode.ROW: return true;
				case ResultCode.DONE: return false;
				default: throw new Exception(Native.errstr(rescode));
			}
		}
		
		public int columnInt(int iCol) {
			return Native.columnInt(STMT, iCol);
		}
		
		public long columnLong(int iCol) {
			return Native.columnLong(STMT, iCol);
		}
		
		public double columnDouble(int iCol) {
			return Native.columnDouble(STMT, iCol);
		}
		
		public String columnString(int iCol) {
			return Native.columnString(STMT, iCol);
		}
		
		public void reset() {
			Native.reset(STMT);
		}
		
		@Override
		public void close() {
			if (!closed) {
				Native._finalize(STMT);
				closed = true;
			}
		}
	}
	
	public static class Exception extends java.lang.Exception {
		Exception(String message) {
			super(message);
		}
	}
	
	static {
		System.loadLibrary("sqlite3wrapper");
	}
}