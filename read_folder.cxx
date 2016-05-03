#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
  struct dirent *folder; 
  std::vector<std::string> dirlist;    

  DIR *path = opendir(argv[1]);
  
  if (path)
  {
    while ((folder = readdir(path)) != NULL)
    {
      dirlist.push_back(folder->d_name);      
    }
    
    closedir(path);
  }
  
  for(int i = 0; i < dirlist.size(); i++)
          std::cout << dirlist[i] << std::endl;

  return(0);
}