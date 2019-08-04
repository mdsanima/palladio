#include "RulePackageFS.h"


namespace {

const std::string SCHEMA_RPK = "rpk:";

bool isRulePackageURI(const char* p) {
	if (p == nullptr)
		return false;

	// needs to start with rpk: schema
	if (std::strncmp(p, SCHEMA_RPK.c_str(), SCHEMA_RPK.length()) != 0)
		return false;

	// needs to contain '!' separator
	if (std::strchr(p, '!') == nullptr)
		return false;

	return true;
}

} // namespace


RulePackageReader::RulePackageReader() {
	//UTaddAbsolutePathPrefix(SCHEMA_RPK.c_str());
}

FS_ReaderStream* RulePackageReader::createStream(const char* source, const UT_Options*) {
	if (!isRulePackageURI(source))
		return nullptr;

	// TODO

	return nullptr;
}


RulePackageInfoHelper::RulePackageInfoHelper() {
	//UTaddAbsolutePathPrefix(SCHEMA_RPK);
}

bool RulePackageInfoHelper::canHandle(const char* source) {
	return isRulePackageURI(source);
}

bool RulePackageInfoHelper::hasAccess(const char* source, int mode) {
	if (!isRulePackageURI(source))
		return false;

	// TODO

	return false;
}

bool RulePackageInfoHelper::getIsDirectory(const char* source) {
	if (!isRulePackageURI(source))
		return false;

//	UT_String homepath;
//	if (fsConvertToStandardPathForInfo(homepath, source)) {
//		FS_Info info(homepath);
//		return info.getIsDirectory();
//	}

	return false;
}

int RulePackageInfoHelper::getModTime(const char* source) {
	if (!isRulePackageURI(source))
		return false;

//	UT_String homepath;
//	if (fsConvertToStandardPathForInfo(homepath, source)) {
//		FS_Info info(homepath);
//		return info.getModTime();
//	}

	return 0;
}

int64 RulePackageInfoHelper::getSize(const char* source) {
	if (!isRulePackageURI(source))
		return false;

//	UT_String homepath;
//	if (fsConvertToStandardPathForInfo(homepath, source)) {
//		FS_Info info(homepath);
//		return info.getFileDataSize();
//	}

	return 0;
}

UT_String RulePackageInfoHelper::getExtension(const char* source) {
	if (!isRulePackageURI(source))
		return FS_InfoHelper::getExtension(source);

	// TODO

	return FS_InfoHelper::getExtension(source);
}

bool RulePackageInfoHelper::getContents(const char* source,
                                   UT_StringArray& contents,
                                   UT_StringArray* dirs) {
	if (!isRulePackageURI(source))
		return false;

//	UT_String homepath;
//	if (fsConvertToStandardPathForInfo(homepath, source)) {
//		FS_Info info(homepath);
//		return info.getContents(contents, dirs);
//	}

	return false;
}
