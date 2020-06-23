#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <dirent.h>

using namespace std;
const char* IMAGE_DIR  = "/home/ftpuser/camera";

int main() {
    // 打开文件夹
    struct dirent *ptr;    
    vector <string> images;
    DIR *dir;
    dir = opendir(IMAGE_DIR);
    printf("文件列表:\n");
    
    while((ptr = readdir(dir)) != NULL) {
		if (strlen(ptr->d_name) > 10)
        	images.push_back(ptr->d_name);
    }
    cout << images[2] << endl;
    closedir(dir);
    return 0;
}