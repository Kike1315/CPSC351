#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  string urls;
  string urlBuffer;
  
  pid_t pid;

  ifstream urlFile("test.txt");

  if (!urlFile.is_open()) {
    fprintf(stderr, "Failed to open the file.");
    exit(1);
  }

  // don't remember how to ifstream works
  while(!urlFile.eof()) {
    urlFile >> urlBuffer;

    if(!urlFile.eof())
      urls.append(urlBuffer);
    urls.append(urlBuffer);

    pid = fork();

    if (pid < 0) {
      perror("fork:");
      exit(1);
    }

    else if (pid == 0) {

      
      if (execlp("/usr/bin/wget", "wget", urls.c_str(), NULL) < 0) {
	  perror("execlp:");
	  exit(1);
	}
	
	else {
	  execlp("/usr/bin/wget", "wget", urls.c_str(), NULL);
	}
    }

    else {
      wait(NULL);
    }
    urlFile.close();
  }

    return 0;
}
