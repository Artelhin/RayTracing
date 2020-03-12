#include <iostream>
#include <cstdint>

#include <string>
#include <vector>
#include <unordered_map>

#include "Bitmap.h"

const uint32_t RED   = 0x000000FF;
const uint32_t GREEN = 0x0000FF00;
const uint32_t BLUE  = 0x00FF0000;

const std::string outFlag = "-out";
const std::string sceneFlag = "-scene";

const int sizeX = 512;
const int sizeY = 512;

int main(int argc, const char** argv)
{
  std::unordered_map<std::string, std::string> cmdLineParams;

  for(int i=0; i<argc; i++)
  {
    std::string key(argv[i]);

    if(key.size() > 0 && key[0]=='-')
    {
      if(i != argc-1) // not last argument
      {
        cmdLineParams[key] = argv[i+1];
        i++;
      }
      else
        cmdLineParams[key] = "";
    }
  }

  std::string outFilePath = "zout.bmp";
  if(cmdLineParams.find(outFlag) != cmdLineParams.end())
    outFilePath = cmdLineParams[outFlag];

  int sceneId = 0;
  if(cmdLineParams.find(sceneFlag) != cmdLineParams.end())
    sceneId = atoi(cmdLineParams[sceneFlag].c_str());

  uint32_t color = 0;
  if(sceneId == 1)
    color = RED;
  else if(sceneId == 2)
    color = RED | GREEN;
  else if(sceneId == 3)
    color = BLUE;
  
  std::vector<uint32_t> image(sizeX*sizeY);
  for(auto& pixel : image)
    pixel = color;

  SaveBMP(outFilePath.c_str(), image.data(), sizeX, sizeY);

  std::cout << "end." << std::endl;
  return 0;
}