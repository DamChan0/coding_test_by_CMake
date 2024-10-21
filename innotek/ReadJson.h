#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>

    typedef struct
    {
        uint32_t confidence;
    } innotekConfig;

    uint32_t readLidarConfidence(char *LidarName);
    uint64_t readLidarMaxAzimuth(char *LidarName);
    uint32_t readLidarMaxRange(char *LidarName);
// uint32_t callreadConfigFunc(uint32_t lidarId, char* LidarName);
#ifdef __cplusplus
}
#endif
