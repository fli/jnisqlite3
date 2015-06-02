#include <stdio.h>
#include "../include/rete_sql_Sqlite3_Native.h"
#include "../include/sqlite3.h"

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_open(JNIEnv *env, jclass cls, jstring filename, jlongArray ppDb, jint flags, jstring zVfs) {
	const char *cFilename = (*env)->GetStringUTFChars(env, filename, 0);
	const char *cVfs = NULL;
	if (zVfs != NULL) {
		const char *cVfs = (*env)->GetStringUTFChars(env, zVfs, 0);
	}
	
	sqlite3 *db;
	int rescode = sqlite3_open_v2(cFilename, &db, flags, cVfs);
	(*env)->SetLongArrayRegion(env, ppDb, 0, 1, (const long *) &db);
	
	(*env)->ReleaseStringUTFChars(env, filename, cFilename);
	if (zVfs != NULL) {
		(*env)->ReleaseStringUTFChars(env, zVfs, cVfs);
	}
	return rescode;
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_prepare(JNIEnv *env, jclass cls, jlong db, jstring sql, jint nByte, jlongArray ppStmt) {
	const char *cSql = (*env)->GetStringUTFChars(env, sql, 0);
	sqlite3_stmt *stmt;
	int rescode = sqlite3_prepare_v2((sqlite3 *) db, cSql, -1, &stmt, NULL);
	(*env)->SetLongArrayRegion(env, ppStmt, 0, 1, (const long *) &stmt);
	(*env)->ReleaseStringUTFChars(env, sql, cSql);
	return rescode;
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_bind__JII (JNIEnv *env, jclass cls, jlong stmt, jint i, jint val) {
	return sqlite3_bind_int((sqlite3_stmt *) stmt, i, val);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_bind__JIJ (JNIEnv *env, jclass cls, jlong stmt, jint i, jlong val) {
	return  sqlite3_bind_int64((sqlite3_stmt *) stmt, i, val);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_bind__JID (JNIEnv *env, jclass cls, jlong stmt, jint i, jdouble val) {
	return sqlite3_bind_double((sqlite3_stmt *) stmt, i, val);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_bind__JILjava_lang_String_2(JNIEnv *env, jclass cls, jlong stmt, jint i, jstring val) {
	const char *cval = (*env)->GetStringUTFChars(env, val, 0);
	int rescode = sqlite3_bind_text((sqlite3_stmt *) stmt, i, cval, -1, SQLITE_TRANSIENT);
	(*env)->ReleaseStringUTFChars(env, val, cval);
	return rescode;
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_step(JNIEnv *env, jclass cls, jlong stmt) {
	return sqlite3_step((sqlite3_stmt *) stmt);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_columnInt(JNIEnv *env, jclass cls, jlong stmt, jint iCol) {
	return sqlite3_column_int((sqlite3_stmt *) stmt, iCol);
}
  
JNIEXPORT jlong JNICALL
Java_rete_sql_Sqlite3_00024Native_columnLong(JNIEnv *env, jclass cls, jlong stmt, jint iCol) {
	return sqlite3_column_int64((sqlite3_stmt *) stmt, iCol);
}

JNIEXPORT jdouble JNICALL
Java_rete_sql_Sqlite3_00024Native_columnDouble(JNIEnv *env, jclass cls, jlong stmt, jint iCol) {
	return sqlite3_column_double((sqlite3_stmt *) stmt, iCol);
}
  
JNIEXPORT jstring JNICALL
Java_rete_sql_Sqlite3_00024Native_columnString(JNIEnv *env, jclass cls, jlong stmt, jint iCol) {
	
	// modified utf-8 problems may arise here
	const char *str = (const char *) sqlite3_column_text((sqlite3_stmt *) stmt, iCol);
	return (*env)->NewStringUTF(env, str);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native__1finalize(JNIEnv *env, jclass cls, jlong stmt) {
	return sqlite3_finalize((sqlite3_stmt *) stmt);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_close(JNIEnv *env, jclass cls, jlong db) {
	return sqlite3_close((sqlite3 *) db);
}

JNIEXPORT jint JNICALL
Java_rete_sql_Sqlite3_00024Native_reset(JNIEnv *env, jclass cls, jlong stmt) {
	return sqlite3_reset((sqlite3_stmt *) stmt);
}

JNIEXPORT jstring JNICALL
Java_rete_sql_Sqlite3_00024Native_errstr(JNIEnv *env, jclass cls, jint errcode) {
	const char *errstr = sqlite3_errstr(errcode);
	return (*env)->NewStringUTF(env, errstr);
}