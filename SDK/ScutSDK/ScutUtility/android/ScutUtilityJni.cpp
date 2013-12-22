/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "ScutUtilityJni.h"
#include "../ScutLocale.h"
#include <android/log.h>
#include "CCScriptSupport.h"
#include "CCLuaEngine.h"
using namespace cocos2d;
#if defined(Scut_IPHONE) || defined(Scut_ANDROID)
#include<errno.h>
#endif

#define SAFE_FREE(p)	if (p) {free(p);	p = NULL;}

#define  LOG_TAG    "ScutUtility"
#include "JniHelper.h"
#define  LOGE(...) //__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGD(...) //__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
/* Header for class com_nd_lib_NdUitilityJni */
	extern JavaVM *gJavaVM;
/*
	jint JNI_OnLoad(JavaVM *vm, void *reserved)
	{
		gJavaVM = vm;
		return JNI_VERSION_1_4;
	}
	*/

	struct ScutUitilityMethodJNI
	{
		JNIEnv *    env;
		jclass      classID;
		jmethodID   methodID;
	};


	static bool getMethodID(struct ScutUitilityMethodJNI& t, const char *className, const char *methodName, const char *paramCode)
	{
		bool ret = 0;
		do 
		{
		JavaVM *gJavaVM = JniHelper::getJavaVM();
		LOGE("getMethodID gJavaVM : %d", gJavaVM);
			if (gJavaVM->GetEnv((void**)&t.env, JNI_VERSION_1_4) != JNI_OK)
			{
				LOGE("Failed to get the environment using GetEnv()");
				break;
			}

			if (gJavaVM->AttachCurrentThread(&t.env, 0) < 0)
			{
				LOGE("Failed to get the environment using AttachCurrentThread()");
				break;
			}

			t.classID = t.env->FindClass(className);
			if (! t.classID)
			{
				LOGE("Failed to find class of %s", className);
				break;
			}

			t.methodID = t.env->GetStaticMethodID(t.classID, methodName, paramCode);
			if (! t.methodID)
			{
				LOGE("Failed to find method id of %s", methodName);
				break;
			}
			ret = true;
		} while (0);

		return ret;
	}

	static char* jstringTostring(JNIEnv* env, jstring jstr)
	{
		char* rtn = NULL;

		// convert jstring to byte array
		jclass clsstring = env->FindClass("java/lang/String");
		jstring strencode = env->NewStringUTF("utf-8");
		jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
		jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
		jsize alen =  env->GetArrayLength(barr);
		jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);

		// copy byte array into char[]
		if (alen > 0)
		{
			rtn = (char*)malloc(alen + 1);
			memcpy(rtn, ba, alen);
			rtn[alen] = 0;
		}
		env->ReleaseByteArrayElements(barr, ba, 0);

		return rtn;
	}

	// char* To jstring  
	static jstring stringTojstring(JNIEnv* env, char* pat)  
	{   
		LOGD((const char*)pat);
		jstring ret;
		jclass strClass = env->FindClass("Ljava/lang/String;");   
		jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");   
		jbyteArray bytes = env->NewByteArray(strlen(pat));   
		env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);   
		jstring encoding = env->NewStringUTF("utf-8");   
		ret = (jstring)env->NewObject(strClass, ctorID, bytes, encoding);   
		LOGD(jstringTostring(env, ret));
		return ret;
	}  

	char* getLanguageJNI()
	{
		ScutUitilityMethodJNI t;
		char* ret = NULL;

		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getLanguage",
			"()Ljava/lang/String;"))
		{
			jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);

			ret = jstringTostring(t.env, str);

		}


		return ret;

	}

	bool  getSDCardStateJNI()
	{
		ScutUitilityMethodJNI t;
		int bRet = 0;
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"isSDCardExist",
			"()I"))
		{
			bRet = (int)t.env->CallStaticIntMethod(t.classID, t.methodID);
		}


		return (bool)bRet;

	}

	char* getAndroidImsi()
	{
		ScutUitilityMethodJNI t;
		char* ret = NULL;

		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getImsi",
			"()Ljava/lang/String;"))
		{
			jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);

			ret = jstringTostring(t.env, str);
		}
		return ret;
	}
	
	char* getAndroidImei()
	{
		ScutUitilityMethodJNI t;
		char* ret = NULL;

		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getImei",
			"()Ljava/lang/String;"))
		{
			jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);

			ret = jstringTostring(t.env, str);
		}
		return ret;
	}

	void localNotification(
		jint	iconResId ,
		jstring	msgTitle ,
		jstring msgContent,
		jint 	intentFlag,
		jint	notifyFlag ,
		jlong	when
		)	
	{
		ScutUitilityMethodJNI t;

		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"localNotification",
			"(ILjava/lang/String;Ljava/lang/String;IIJ)V"))
		{
			t.env->CallStaticObjectMethod(t.classID, t.methodID,
				iconResId , 
				msgTitle , 
				msgContent, 
				intentFlag, 
				notifyFlag, 
				when
				);
		}
	}

	void scheduleAndroidLocalNotification(std::string strSoundName, int iconResId, std::string strMsgTitle, std::string strMsgContent, double when, unsigned char hasAction, int repeatInterval)
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter scheduleAndroidLocalNotification()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"scheduleLocalNotification",
			"(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;JZI)V"))
		{
			jstring soundName = (strSoundName.length() == 0) ? NULL : (jstring)t.env->NewStringUTF(strSoundName.c_str());
			jstring msgTitle = (strMsgTitle.length() == 0) ? NULL : (jstring)t.env->NewStringUTF(strMsgTitle.c_str());
			jstring msgContent = (strMsgContent.length() == 0) ? NULL : (jstring)t.env->NewStringUTF(strMsgContent.c_str());
			LOGD("***CallStaticObjectMethod scheduleAndroidLocalNotification()***");
			t.env->CallStaticObjectMethod(t.classID, t.methodID,
				soundName,
				(jint)iconResId , 
				msgTitle,
				msgContent,
				(jlong)when,
				(jboolean)hasAction,
				(jint)repeatInterval
				);
			LOGD("Success scheduleAndroidLocalNotification.");
		}
	}
	
	void cancelAndroidNotification(int id)
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter cancelAndroidNotification()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"cancelNotification",
			"(I)V"))
		{
			LOGD("***CallStaticObjectMethod cancelAndroidNotification()***");
			t.env->CallStaticObjectMethod(t.classID, t.methodID, (jint)id);
			LOGD("Success cancelAndroidNotification.");
		}
	}

	void cancelAndroidNotifications()
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter cancelAndroidNotifications()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"cancelAllNotifications",
			"()V"))
		{
			LOGD("***CallStaticObjectMethod cancelAndroidNotifications()***");
			t.env->CallStaticObjectMethod(t.classID, t.methodID);
			LOGD("Success cancelAndroidNotifications.");
		}
	}

	void androidCopyTextToClipBoard(std::string content)
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter androidCopyTextToClipBoard()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"copyTextToClipBoard",
			"(Ljava/lang/String;)V"))
		{
			LOGD("***androidCopyTextToClipBoard copyTextToClipBoard()***");
			t.env->CallStaticObjectMethod(t.classID, t.methodID,
				(jstring)t.env->NewStringUTF(content.c_str())
				);
			LOGD("Success androidCopyTextToClipBoard.");
		}
	}

	char* androidGetTextFromClipBoard()
	{
		ScutUitilityMethodJNI t;
		char* ret = NULL;

		LOGD("***enter androidGetTextFromClipBoard()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getTextFromClipBoard",
			"()Ljava/lang/String;"))
		{
			LOGD("***CallStaticObjectMethod androidGetTextFromClipBoard()***");
			jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);

			if (str != NULL)
			{
				ret = jstringTostring(t.env, str);
			}
			LOGD("Success androidGetTextFromClipBoard.");
		}
		return ret;
	}

	void androidLaunchApp(std::string packageName)
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter androidLaunchApp()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"launchApp",
			"(Ljava/lang/String;)V"))
		{
			LOGD("***CallStaticObjectMethod androidLaunchApp()***");
			t.env->CallStaticObjectMethod(t.classID, t.methodID,
				(jstring)t.env->NewStringUTF(packageName.c_str())
				);
			LOGD("Success androidLaunchApp.");
		}
	}

	std::string androidGetInstalledApps()
	{
		ScutUitilityMethodJNI t;
		char* ret = NULL;

		LOGD("***enter androidGetInstalledApps()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getInstalledApps",
			"()Ljava/lang/String;"))
		{
			LOGD("***CallStaticObjectMethod androidGetInstalledApps()***");
			jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);

			if (str != NULL)
			{
				ret = jstringTostring(t.env, str);
				LOGD("ret = %s", ret);
			}
			LOGD("Success androidGetInstalledApps.");
		}

		std::string strRet = std::string(ret == NULL ? "" : ret);
		LOGD("strRet = %s", strRet.c_str());
		SAFE_FREE(ret);
		return strRet;
	}

	std::string androidGetCurrentAppId()
	{
		ScutUitilityMethodJNI t;
		char* ret = NULL;

		LOGD("***enter androidGetCurrentAppId()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getCurrentAppId",
			"()Ljava/lang/String;"))
		{
			LOGD("***CallStaticObjectMethod androidGetCurrentAppId()***");
			jstring str = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);

			if (str != NULL)
			{
				ret = jstringTostring(t.env, str);
				LOGD("ret = %s", ret);
			}
			LOGD("Success androidGetCurrentAppId.");
		}

		std::string strRet = std::string(ret == NULL ? "" : ret);
		LOGD("strRet = %s", strRet.c_str());
		SAFE_FREE(ret);
		return strRet;
	}

	void androidInstallPackage(std::string apkFilePath)
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter androidInstallPackage()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"installPackage",
			"(Ljava/lang/String;)V"))
		{
			LOGD("***CallStaticObjectMethod androidInstallPackage()***");
			t.env->CallStaticObjectMethod(t.classID, t.methodID,
				(jstring)t.env->NewStringUTF(apkFilePath.c_str())
				);
			LOGD("Success androidInstallPackage.");
		}
	}

	bool androidCheckAppInstalled(std::string packageName, bool bForceUpdate)
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter androidCheckAppInstalled()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"checkAppInstalled",
			"(Ljava/lang/String;Z)Z"))
		{
			LOGD("***CallStaticObjectMethod androidCheckAppInstalled()***");
			bool bRet = (bool)t.env->CallStaticObjectMethod(t.classID, t.methodID,
				(jstring)t.env->NewStringUTF(packageName.c_str()),
				(jboolean)(bForceUpdate ? 1 : 0)
				);
			LOGD("Success androidCheckAppInstalled.");

			return (bool)bRet;
		}

		return false;
	}

// 	void androidRegisterWebviewCallback(std::string strFun)
// 	{
// 		ScutUitilityMethodJNI t;
// 
// 		LOGD("***enter registerWebviewCallback()***");
// 		if (getMethodID(t, 
// 			"org/cocos2dx/lib/WebViewActivity",
// 			"registerWebviewCallback",
// 			"(Ljava/lang/String;)V"))
// 		{
// 			LOGD("***CallStaticObjectMethod registerWebviewCallback()***");
// 			t.env->CallStaticObjectMethod(t.classID, t.methodID,
// 				(jstring)t.env->NewStringUTF(strFun.c_str())
// 				);
// 			LOGD("Success registerWebviewCallback.");
// 		}
// 	}

	/*void excWebviewCallback(std::string strFun, int code, std::string strParam)
	{
		LOGD("excWebviewCallback() begin");
		if (strFun.length() > 0)
		{
			LOGD("excWebviewCallback().  strFun.length() > 0");
			LuaEngine* pEngine = (LuaEngine*)cocos2d::CCScriptEngineManager::sharedScriptEngineManager()->getScriptEngine();
			if (pEngine)
			{
				LOGD("excWebviewCallback().  pEngine != null.");
				pEngine->executeWebviewEvent(strFun.c_str(), code, strParam.c_str());
			}
			else
			{
				LOGD("excWebviewCallback().  pEngine != null.");
			}
		}
		LOGD("excWebviewCallback() end");
	}*/

	int androidGetActiveNetwork()
	{
		ScutUitilityMethodJNI t;

		LOGD("***enter androidGetActiveNetwork()***");
		if (getMethodID(t, 
			"com/nd/lib/NdUtilityJni",
			"getActiveNetwork",
			"()I"))
		{
			LOGD("***CallStaticIntMethod getActiveNetwork()***");
			int iRet = (int)t.env->CallStaticIntMethod(t.classID, t.methodID);
			LOGD("Success getActiveNetwork.");

			return iRet;
		}

		return 0;
	}


void  JNICALL Java_com_nd_lib_NdUtilityJni_initTest
(JNIEnv *, jclass)
{
	LOGD(ScutUtility::CLocale::getLanguage());
}


void  JNICALL Java_com_nd_application_MainApplication_localNotification
(JNIEnv *env, jobject thiz,
 jint	iconResId ,
 jstring	msgTitle ,
 jstring msgContent,
 jint 	intentFlag,
 jint	notifyFlag ,
 jlong	when
 )	
{
	LOGD("Java_com_nd_application_MainApplication_localNotification");

	localNotification(
		iconResId , 
		msgTitle , 
		msgContent, 
		intentFlag, 
		notifyFlag, 
		when
		);
		
}

void  JNICALL Java_com_nd_application_MainApplication_scheduleLocalNotification(JNIEnv *env, jobject thiz,
															   jstring	soundName,
															   jint		iconResId ,
															   jstring	msgTitle ,
															   jstring	msgContent,
															   jlong	when,
															   jboolean hasAction,
															   jint		repeatInterval
															   )	
{
	LOGD("Java_com_nd_application_MainApplication_scheduleLocalNotification");
	char* szSoundName = jstringTostring(env, soundName);
	char* szMsgTitle = jstringTostring(env, msgTitle);
	char* szMsgContent = jstringTostring(env, msgContent);
	scheduleAndroidLocalNotification((std::string)szSoundName, (int)iconResId, (std::string)szMsgTitle, (std::string)szMsgContent, (double)when, (unsigned char)hasAction, (int)repeatInterval);
	SAFE_FREE(szSoundName);
	SAFE_FREE(szMsgTitle);
	SAFE_FREE(szMsgContent);
}

void JNICALL Java_com_nd_application_MainApplication_copyTextToClipBoard(JNIEnv *env, jobject thiz, jstring content)
{
	char* szContent = jstringTostring(env, content);
	androidCopyTextToClipBoard((std::string)szContent);
	SAFE_FREE(szContent);
}

void JNICALL Java_org_cocos2dx_lib_WebViewActivity_DoWebviewCallback(JNIEnv * env, jclass thisCls, jint nHandler, jint type, jstring strParam)
{
	LOGE("Enter DoWebviewCallback ");
	char* szParam = jstringTostring(env, strParam);
	//excWebviewCallback(nHandler, type, (std::string)szParam);
	SAFE_FREE(szParam);
}