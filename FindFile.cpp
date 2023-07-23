#include "FindFile.h"

void searchFile(const filesystem::path& directory, const string& filename) {
    if (!filesystem::exists(directory) || !filesystem::is_directory(directory))
        return;

    for (const auto& entry : filesystem::directory_iterator(directory)) {
        if (entry.is_directory()) {
            thread searchThread(searchFile, entry.path(), filename);
            searchThread.join();
        } else if (entry.is_regular_file() && entry.path().filename() == filename) {
            lock_guard<mutex> lock(printMutex);
            cout << "Found file: " << entry.path() << endl;
        }
    }
}