#include "api.hpp"

/*************************************************************
 * This function is used as a callback function to help 
 * allocate memory being sent to the server. This function will
 * return the size of the memory allocated to be used with the
 * data being sent. This function will be used when setting the
 * curl_easy_opt CURLOPT_WRITEFUNCTION with this function as 
 * its callback. Afterwards the data allocated for will get
 * passed to the CURLOPT_WRITEDATA curl_easy_opt setting to
 * complete the necessary action of allocating memory.
 *************************************************************/
static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, void *userp){
  
  size_t realSize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  char *ptr = (char *) realloc(mem->memory, mem->size + realSize + 1);
  if(!ptr) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realSize);
  mem->size += realSize;
  mem->memory[mem->size] = 0;
 
  return realSize;
};

/*************************************************************
 * This function is used to globally initialize curl. We must
 * wrap this function, and we cannot include raylib.h and
 * curl.h in the same file because curl.h includes windows.h
 *************************************************************/
void CurlGlobalInit(void) {
    curl_global_init(CURL_GLOBAL_ALL);
};

/*************************************************************
 * This function is used to globally cleanup curl. We must
 * also wrap this function, for the same reason as above.
 *************************************************************/
void CurlGlobalCleanup(void) {
    curl_global_cleanup();
};