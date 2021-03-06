/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class rete_sql_Sqlite3_Native */

#ifndef _Included_rete_sql_Sqlite3_Native
#define _Included_rete_sql_Sqlite3_Native
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    open
 * Signature: (Ljava/lang/String;[JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_open
  (JNIEnv *, jclass, jstring, jlongArray, jint, jstring);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    prepare
 * Signature: (JLjava/lang/String;I[J)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_prepare
  (JNIEnv *, jclass, jlong, jstring, jint, jlongArray);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    bind
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_bind__JII
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    bind
 * Signature: (JIJ)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_bind__JIJ
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    bind
 * Signature: (JID)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_bind__JID
  (JNIEnv *, jclass, jlong, jint, jdouble);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    bind
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_bind__JILjava_lang_String_2
  (JNIEnv *, jclass, jlong, jint, jstring);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    step
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_step
  (JNIEnv *, jclass, jlong);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    columnInt
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_columnInt
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    columnLong
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_rete_sql_Sqlite3_00024Native_columnLong
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    columnDouble
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_rete_sql_Sqlite3_00024Native_columnDouble
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    columnString
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_rete_sql_Sqlite3_00024Native_columnString
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    _finalize
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native__1finalize
  (JNIEnv *, jclass, jlong);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    close
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_close
  (JNIEnv *, jclass, jlong);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    reset
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_rete_sql_Sqlite3_00024Native_reset
  (JNIEnv *, jclass, jlong);

/*
 * Class:     rete_sql_Sqlite3_Native
 * Method:    errstr
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_rete_sql_Sqlite3_00024Native_errstr
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif
