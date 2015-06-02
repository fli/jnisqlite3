import rete.sql.Sqlite3;
import rete.sql.Sqlite3.Statement;

class Sqlite3Tests {
	
	static void run() {
		try (
			Sqlite3 db = new Sqlite3("test.db");
		) {
			Statement stmt = db.prepare("create table user(id integer primary key, email text, password text)");
			stmt.step();
			stmt.close();
			Statement insert = db.prepare("insert into user(email, password) values(?, ?)");
			insert.bind(1, "abc").bind(2, "123");
			insert.step();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	
	public static void main(String args[]) {
		Sqlite3Tests.run();
	}
}