#pragma once

#include <string>
#include <vector>

/**
 * DEBUG 창에 포멧팅된 문자열을 출력합니다.
 * 이때, 이 기능은 DEBUG_MODE와 RELWITHDEBINFO_MODE 때만 동작합니다.
 */
void DebugPrintF(const char* format, ...);

/** 표준 문자열 기반의 문자열 포멧팅을 수행합니다. */
std::string PrintF(const char* format, ...);

/** 표준 문자열 기반의 문자열 포멧팅을 수행합니다. */
std::wstring PrintF(const wchar_t* format, ...);

/** 파일을 읽어 벡터에 저장합니다. */
bool ReadFile(const std::string& path, std::vector<uint8_t>& outBuffer, std::string& outErrMsg);

/** 파일을 읽어 벡터에 저장합니다. */
bool ReadFile(const std::wstring& path, std::vector<uint8_t>& outBuffer, std::string& outErrMsg);

/** 벡터에 저장된 버퍼를 파일에 씁니다. */
bool WriteFile(const std::string& path, const std::vector<uint8_t>& buffer, std::string& outErrMsg);

/** 벡터에 저장된 버퍼를 파일에 씁니다. */
bool WriteFile(const std::wstring& path, const std::vector<uint8_t>& buffer, std::string& outErrMsg);

/** 현재 시스템 시간 값을 얻습니다. */
void GetCurrentSystemTime(int32_t& outYear, int32_t& outMonth, int32_t& outDay, int32_t& outHour, int32_t& outMinute, int32_t& outSecond);

/** 현재 시스템 시간을 문자열로 얻습니다. */
std::string GetCurrentSystemTimeAsString();

/** 현재 시스템 시간을 문자열로 얻습니다. */
static std::wstring GetCurrentSystemTimeAsWString();

/** 디렉토리를 생성합니다. */
bool MakeDirectory(const std::string& path, std::string& outErrMsg);

/** 디렉토리를 생성합니다. */
bool MakeDirectory(const std::wstring& path, std::string& outErrMsg);