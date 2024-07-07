#ifndef api_hpp
#define api_hpp

// System Libraries
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

// User Libraries
// N/A

// External Libraries
#include <curl/curl.h>
#include <curl/easy.h>
#include "../include/nlohmann/json.hpp"
using json = nlohmann::json;

// Created struct for memory being allocated.
struct MemoryStruct {
  char *memory;
  size_t size;
};

// Function prototypes for networking with libcurl
static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, void *userp);
void CurlGlobalInit(void);
void CurlGlobalCleanup(void);

// json CurlCreateAccount(json registration);
// json CurlLoginAccount(json login);

#endif /* api_hpp */