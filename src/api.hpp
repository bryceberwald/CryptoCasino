#ifndef api_hpp
#define api_hpp

// System Libraries
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

// External Libraries
#include "../include/curl/curl.h"
#include "../include/curl/easy.h"

// Created struct for memory being allocated.
struct MemoryStruct {
  char *memory;
  size_t size;
};

// Function prototypes for networking with libcurl
static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, void *userp);
void CurlGlobalInit(void);
void CurlGlobalCleanup(void);

#endif /* api_hpp */