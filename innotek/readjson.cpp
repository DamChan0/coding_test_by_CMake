#include "ReadJson.h"

#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <memory>

#include "jsoncpp/json/json.h"

using namespace std;
namespace fs = std::experimental::filesystem;

inline void GetJsonVal(Json::Value *Json)
{
    std::string program_path = fs::current_path();
    std::string filename = program_path + "/Config/innotekConfig.json";

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open JSON file." << std::endl;
    }

    // JSON 파싱을 위한 루트 JSON 객체 생성
    Json::CharReaderBuilder builder;
    std::string errs;

    // 파일로부터 JSON 파싱
    if (!Json::parseFromStream(builder, file, Json, &errs))
    {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
    }
}

uint32_t readLidarConfidence(char *LidarName)
{
    std::string FilePath = "/Config/innotekConfig.json";
    Json::Value root;
    GetJsonVal(&root);

    Json::Value configs = root["Configs"];
    for (const auto &config : configs)
    {
        std::string name = config["name"].asString();
        if (name == LidarName)
        {
            uint32_t confidence = config["parameters"]["confidence"].asUInt();
            return confidence;
        }
    }

    return 0;
}

uint64_t readLidarMaxAzimuth(char *LidarName)
{
    std::string FilePath = "/Config/innotekConfig.json";
    Json::Value root;
    GetJsonVal(&root);

    Json::Value configs = root["Configs"];
    for (const auto &config : configs)
    {
        std::string name = config["name"].asString();
        if (name == LidarName)
        {
            uint64_t MaxAzimuth = config["parameters"]["MaxAzimuth"].asUInt64();
            return MaxAzimuth;
        }
    }

    return 0;
}

uint32_t readLidarMaxRange(char *LidarName)
{
    std::string FilePath = "/Config/innotekConfig.json";
    Json::Value root;
    GetJsonVal(&root);

    Json::Value configs = root["Configs"];
    for (const auto &config : configs)
    {
        std::string name = config["name"].asString();
        if (name == LidarName)
        {
            uint32_t MaxRange = config["parameters"]["MaxRange"].asUInt();
            return MaxRange;
        }
    }

    return 0;
}
