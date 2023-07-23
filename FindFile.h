#ifndef _FIND_FILE_H
#define _FIND_FILE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <filesystem>
#include <string>

using namespace std;

static mutex printMutex;

void searchFile(const filesystem::path& directory, const string& filename);

#endif