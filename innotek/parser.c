#include "Parser.h"

#include <errno.h> // errno 변수를 사용하기 위해 추가
#include "ReadJson.h"
#define M_PI 3.14159265358979323846 /* pi */

// debug용 512 채널 데이터 좌표 계산용
float32_t debugElevationValue[512] = {
    -25, -24.9414, -24.8828, -24.8242, -24.7656, -24.707, -24.6484,
    -24.5898, -24.5312, -24.4727, -24.4141, -24.3555, -24.2969, -24.2383,
    -24.1797, -24.1211, -24.0625, -24.0039, -23.9453, -23.8867, -23.8281,
    -23.7695, -23.7109, -23.6523, -23.5938, -23.5352, -23.4766, -23.418,
    -23.3594, -23.3008, -23.2422, -23.1836, -23.125, -23.0664, -23.0078,
    -22.9492, -22.8906, -22.832, -22.7734, -22.7148, -22.6562, -22.5977,
    -22.5391, -22.4805, -22.4219, -22.3633, -22.3047, -22.2461, -22.1875,
    -22.1289, -22.0703, -22.0117, -21.9531, -21.8945, -21.8359, -21.7773,
    -21.7188, -21.6602, -21.6016, -21.543, -21.4844, -21.4258, -21.3672,
    -21.3086, -21.25, -21.1914, -21.1328, -21.0742, -21.0156, -20.957,
    -20.8984, -20.8398, -20.7812, -20.7227, -20.6641, -20.6055, -20.5469,
    -20.4883, -20.4297, -20.3711, -20.3125, -20.2539, -20.1953, -20.1367,
    -20.0781, -20.0195, -19.9609, -19.9023, -19.8438, -19.7852, -19.7266,
    -19.668, -19.6094, -19.5508, -19.4922, -19.4336, -19.375, -19.3164,
    -19.2578, -19.1992, -19.1406, -19.082, -19.0234, -18.9648, -18.9062,
    -18.8477, -18.7891, -18.7305, -18.6719, -18.6133, -18.5547, -18.4961,
    -18.4375, -18.3789, -18.3203, -18.2617, -18.2031, -18.1445, -18.0859,
    -18.0273, -17.9688, -17.9102, -17.8516, -17.793, -17.7344, -17.6758,
    -17.6172, -17.5586, -17.5, -17.4414, -17.3828, -17.3242, -17.2656,
    -17.207, -17.1484, -17.0898, -17.0312, -16.9727, -16.9141, -16.8555,
    -16.7969, -16.7383, -16.6797, -16.6211, -16.5625, -16.5039, -16.4453,
    -16.3867, -16.3281, -16.2695, -16.2109, -16.1523, -16.0938, -16.0352,
    -15.9766, -15.918, -15.8594, -15.8008, -15.7422, -15.6836, -15.625,
    -15.5664, -15.5078, -15.4492, -15.3906, -15.332, -15.2734, -15.2148,
    -15.1562, -15.0977, -15.0391, -14.9805, -14.9219, -14.8633, -14.8047,
    -14.7461, -14.6875, -14.6289, -14.5703, -14.5117, -14.4531, -14.3945,
    -14.3359, -14.2773, -14.2188, -14.1602, -14.1016, -14.043, -13.9844,
    -13.9258, -13.8672, -13.8086, -13.75, -13.6914, -13.6328, -13.5742,
    -13.5156, -13.457, -13.3984, -13.3398, -13.2812, -13.2227, -13.1641,
    -13.1055, -13.0469, -12.9883, -12.9297, -12.8711, -12.8125, -12.7539,
    -12.6953, -12.6367, -12.5781, -12.5195, -12.4609, -12.4023, -12.3438,
    -12.2852, -12.2266, -12.168, -12.1094, -12.0508, -11.9922, -11.9336,
    -11.875, -11.8164, -11.7578, -11.6992, -11.6406, -11.582, -11.5234,
    -11.4648, -11.4062, -11.3477, -11.2891, -11.2305, -11.1719, -11.1133,
    -11.0547, -10.9961, -10.9375, -10.8789, -10.8203, -10.7617, -10.7031,
    -10.6445, -10.5859, -10.5273, -10.4688, -10.4102, -10.3516, -10.293,
    -10.2344, -10.1758, -10.1172, -10.0586, -10, -9.94141, -9.88281,
    -9.82422, -9.76562, -9.70703, -9.64844, -9.58984, -9.53125, -9.47266,
    -9.41406, -9.35547, -9.29688, -9.23828, -9.17969, -9.12109, -9.0625,
    -9.00391, -8.94531, -8.88672, -8.82812, -8.76953, -8.71094, -8.65234,
    -8.59375, -8.53516, -8.47656, -8.41797, -8.35938, -8.30078, -8.24219,
    -8.18359, -8.125, -8.06641, -8.00781, -7.94922, -7.89062, -7.83203,
    -7.77344, -7.71484, -7.65625, -7.59766, -7.53906, -7.48047, -7.42188,
    -7.36328, -7.30469, -7.24609, -7.1875, -7.12891, -7.07031, -7.01172,
    -6.95312, -6.89453, -6.83594, -6.77734, -6.71875, -6.66016, -6.60156,
    -6.54297, -6.48438, -6.42578, -6.36719, -6.30859, -6.25, -6.19141,
    -6.13281, -6.07422, -6.01562, -5.95703, -5.89844, -5.83984, -5.78125,
    -5.72266, -5.66406, -5.60547, -5.54688, -5.48828, -5.42969, -5.37109,
    -5.3125, -5.25391, -5.19531, -5.13672, -5.07812, -5.01953, -4.96094,
    -4.90234, -4.84375, -4.78516, -4.72656, -4.66797, -4.60938, -4.55078,
    -4.49219, -4.43359, -4.375, -4.31641, -4.25781, -4.19922, -4.14062,
    -4.08203, -4.02344, -3.96484, -3.90625, -3.84766, -3.78906, -3.73047,
    -3.67188, -3.61328, -3.55469, -3.49609, -3.4375, -3.37891, -3.32031,
    -3.26172, -3.20312, -3.14453, -3.08594, -3.02734, -2.96875, -2.91016,
    -2.85156, -2.79297, -2.73438, -2.67578, -2.61719, -2.55859, -2.5,
    -2.44141, -2.38281, -2.32422, -2.26562, -2.20703, -2.14844, -2.08984,
    -2.03125, -1.97266, -1.91406, -1.85547, -1.79688, -1.73828, -1.67969,
    -1.62109, -1.5625, -1.50391, -1.44531, -1.38672, -1.32812, -1.26953,
    -1.21094, -1.15234, -1.09375, -1.03516, -0.976562, -0.917969, -0.859375,
    -0.800781, -0.742188, -0.683594, -0.625, -0.566406, -0.507812, -0.449219,
    -0.390625, -0.332031, -0.273438, -0.214844, -0.15625, -0.0976562, -0.0390625,
    0.0195312, 0.078125, 0.136719, 0.195312, 0.253906, 0.3125, 0.371094,
    0.429688, 0.488281, 0.546875, 0.605469, 0.664062, 0.722656, 0.78125,
    0.839844, 0.898438, 0.957031, 1.01562, 1.07422, 1.13281, 1.19141,
    1.25, 1.30859, 1.36719, 1.42578, 1.48438, 1.54297, 1.60156,
    1.66016, 1.71875, 1.77734, 1.83594, 1.89453, 1.95312, 2.01172,
    2.07031, 2.12891, 2.1875, 2.24609, 2.30469, 2.36328, 2.42188,
    2.48047, 2.53906, 2.59766, 2.65625, 2.71484, 2.77344, 2.83203,
    2.89062, 2.94922, 3.00781, 3.06641, 3.125, 3.18359, 3.24219,
    3.30078, 3.35938, 3.41797, 3.47656, 3.53516, 3.59375, 3.65234,
    3.71094, 3.76953, 3.82812, 3.88672, 3.94531, 4.00391, 4.0625,
    4.12109, 4.17969, 4.23828, 4.29688, 4.35547, 4.41406, 4.47266,
    4.53125, 4.58984, 4.64844, 4.70703, 4.76562, 4.82422, 4.88281,
    4.94141};

// Argo LiDAR 128채널 데이터 계산용
float32_t omegaOffset[128] = {
    -24.765625, -24.531250, -24.296875, -24.062500, -23.828125, -23.593750,
    -23.359375, -23.125000, -22.890625, -22.656250, -22.421875, -22.187500,
    -21.953125, -21.718750, -21.484375, -21.250000, -21.015625, -20.781250,
    -20.546875, -20.312500, -20.078125, -19.843750, -19.609375, -19.375000,
    -19.140625, -18.906250, -18.671875, -18.437500, -18.203125, -17.968750,
    -17.734375, -17.500000, -17.265625, -17.031250, -16.796875, -16.562500,
    -16.328125, -16.093750, -15.859375, -15.625000, -15.390625, -15.156250,
    -14.921875, -14.687500, -14.453125, -14.218750, -13.984375, -13.750000,
    -13.515625, -13.281250, -13.046875, -12.812500, -12.578125, -12.343750,
    -12.109375, -11.875000, -11.640625, -11.406250, -11.171875, -10.937500,
    -10.703125, -10.468750, -10.234375, -10.000000, -9.765625, -9.531250,
    -9.296875, -9.062500, -8.828125, -8.593750, -8.359375, -8.125000,
    -7.890625, -7.656250, -7.421875, -7.187500, -6.953125, -6.718750,
    -6.484375, -6.250000, -6.015625, -5.781250, -5.546875, -5.312500용용 - 5.078125, -4.843750, -4.609375, -4.375000, -4.140625, -3.906250,
    -3.671875, -3.437500, -3.203125, -2.968750, -2.734375, -2.500000,
    -2.265625, -2.031250, -1.796875, -1.562500, -1.328125, -1.093750,
    -0.859375, -0.625000, -0.390625, -0.156250, 0.078125, 0.312500,
    0.546875, 0.781250, 1.015625, 1.250000, 1.484375, 1.718750,
    1.953125, 2.187500, 2.421875, 2.656250, 2.890625, 3.125000,
    3.359375, 3.593750, 3.828125, 4.062500, 4.296875, 4.531250,
    4.765625, 5.000000};

static float32_t MRazimuthFactor = 0;
void parserInnotekArgoMR(SensorInfo_t *sInfo, OutputData_t *output)
{
    fColorRGBA_t color = {.a = 1, .b = 1, .g = 1, .r = 0.5};
    UNUSED(output);
    int32_t msgSz = 8260;
    SensorBuf_t *parserIn = &sInfo->bufInfo.parserIn;
    LidarPoint_t *lidarPnt = sInfo->bufInfo.lidarOutBuffer;
    int32_t pointNum = 0;
    uint32_t numOfCol = 4;
    int32_t numOfChannel = 128;
    uint64_t timestamp[4] = {0};
    float32_t rho_m = 0.;
    float32_t x_m = 0.;
    float32_t y_m = 0.;
    float32_t z_m = 0.;
    float32_t range_m = 0.;
    float32_t rangeFactor = 0.0046875;
    uint32_t ofs = 0;
    uint32_t curSz = 0;
    uint32_t azimuth_col = 0;
    InnoteckMR_Packet *innoMR;
    UNUSED(innoMR);
    UNUSED(timestamp);
    uint8_t *dataBuff = parserIn->buf.data;
    uint32_t confIdThd = readLidarConfidence(sInfo->common.sensorName);
    uint32_t MaxRange = readLidarMaxRange(sInfo->common.sensorName);
    uint64_t maxAzimuth = readLidarMaxAzimuth(sInfo->common.sensorName);
    static uint32_t preCustomAz = 0;

    while (curSz < (*parserIn->buf.usingSz))
    {
        innoMR = (InnoteckMR_Packet *)&dataBuff[ofs];
        ofs += sizeof(InnoteckMR_Packet);

        if (preCustomAz != maxAzimuth)
        {
            MRazimuthFactor = 360. / (maxAzimuth + 1);
        }
        preCustomAz = maxAzimuth;
        for (uint32_t i = 0; i < numOfCol; i++)
        {
            timestamp[i] = innoMR->body.timestamp.col[i];
        }

        uint32_t range_ofs = 0;
        for (uint32_t j = 0; j < 2; j++)
        {
            for (azimuth_col = 0; azimuth_col < numOfCol; azimuth_col++)
            {
                uint32_t elevationIndex = 0;
                for (uint32_t i = numOfChannel + range_ofs - 1; i > range_ofs; i--)
                {
                    float32_t azimuth_deg = 0;
                    UNUSED(azimuth_deg);
                    fPoint3D_t *p = &lidarPnt->pnt[pointNum].coord_m;
                    range_m = innoMR->body.range.return_return0[i] * rangeFactor;
                    if (range_m < 0.1 || range_m > MaxRange)
                    {
                        elevationIndex++;
                        continue;
                    }
                    if (confIdThd < innoMR->body.confidences[i])
                    {
                        azimuth_deg =
                            innoMR->body.azimuth_raw[azimuth_col] * MRazimuthFactor;

                        if (azimuth_deg > 360. || azimuth_deg < 0)
                        {
                            PrintDbg("invalied deg %f", azimuth_deg);
                        }

                        rho_m = range_m * vueCosDegree(omegaOffset[elevationIndex]);
                        z_m = range_m * vueSinDegree(omegaOffset[elevationIndex]);
                        x_m = rho_m * vueSinDegree(azimuth_deg);
                        y_m = rho_m * vueCosDegree(azimuth_deg);
                        p->x = x_m;
                        p->y = y_m;
                        p->z = z_m;
                        calibrate(sInfo->lidar.cal, p);
                        lidarPnt->pntInfo[pointNum].radius_m = range_m;
                        lidarPnt->pntInfo[pointNum].rho_m = rho_m;
                        lidarPnt->pntInfo[pointNum].theta_deg = CalcTheta(p->x, p->y);

                        setPCDcolor(&lidarPnt->pnt[pointNum].color_rgba, &color);
                        pointNum++;
                        elevationIndex++;
                    }
                    else
                    {
                        elevationIndex++;
                    }
                }
                range_ofs += numOfChannel;
            }
        }
        curSz += msgSz;
    }
    *lidarPnt->pntNum = pointNum;
}

static double azimuthFactor = 0;
void parserInnotekArgoMR_Debug(SensorInfo_t *sInfo, OutputData_t *output)
{
    fColorRGBA_t color = {.a = 1, .b = 0, .g = 1, .r = 0.4};
    UNUSED(output);
    InnotekMR_Debug *debuge_data;
    int32_t packet_Sz = 6176;
    uint32_t pixelNum = 512;
    float32_t rangeFactor = 0.077;
    SensorBuf_t *parserIn = &sInfo->bufInfo.parserIn;
    LidarPoint_t *lidarPnt = sInfo->bufInfo.lidarOutBuffer;
    uint32_t pointNum = 0;
    uint32_t curLoc = 0;
    int32_t ROICLoc = 0;
    uint32_t pixelLoc = 0;
    uint32_t bodySz = 3072;
    uint16_t pixelData1[512] = {0};
    UNUSED(pixelData1);
    float32_t range_m = 0;
    float32_t x_m = 0.;
    float32_t y_m = 0.;
    float32_t z_m = 0;
    float32_t rho_m = 0.;

    double MaxRange = readLidarMaxRange(sInfo->common.sensorName);
    double maxAzimuth = readLidarMaxAzimuth(sInfo->common.sensorName);
    static uint32_t preCustomAz = 0;
    while (curLoc < *parserIn->buf.usingSz)
    {
        uint32_t swtichLoc = 1;
        debuge_data = (InnotekMR_Debug *)&parserIn->buf.data[curLoc];

        if (preCustomAz != maxAzimuth)
        {
            azimuthFactor = 360. / (maxAzimuth + 1);
        }
        preCustomAz = maxAzimuth;

        swtichLoc = 1;
        uint32_t index = 0;
        for (ROICLoc = 1; ROICLoc < 3072; ROICLoc += 48)
        {
            pixelLoc++;
            if (swtichLoc == 17)
            {
                break;
            }
            if ((bodySz - ROICLoc) < 48)
            {
                swtichLoc += 2;
                pixelData1[index] = debuge_data->body.pixel[ROICLoc];
                ROICLoc = swtichLoc - 48;
                index++;
                continue;
            }
            pixelData1[index] = debuge_data->body.pixel[ROICLoc];
            index++;
        }

        double azimuth_deg = debuge_data->header.azimuth * azimuthFactor;
        for (uint32_t j = 0; j < pixelNum; j++)
        {
            range_m = pixelData1[j] * rangeFactor;
            if (range_m > MaxRange)
            {
                continue;
            }
            rho_m = range_m * vueCosDegree(debugElevationValue[j]);
            z_m = range_m * vueSinDegree(debugElevationValue[j]);
            x_m = rho_m * vueSinDegree(azimuth_deg);
            y_m = rho_m * vueCosDegree(azimuth_deg);
            fPoint3D_t *p = &lidarPnt->pnt[pointNum].coord_m;
            p->x = x_m;
            p->y = y_m;
            p->z = z_m;
            calibrate(sInfo->lidar.cal, p);
            lidarPnt->pntInfo[pointNum].radius_m = range_m;
            lidarPnt->pntInfo[pointNum].rho_m = rho_m;
            lidarPnt->pntInfo[pointNum].theta_deg = CalcTheta(p->x, p->y);
            setPCDcolor(&lidarPnt->pnt[pointNum].color_rgba, &color);
            pointNum++;
        }
        memset(pixelData1, 0, sizeof(pixelData1));
        index = 0;
        curLoc += packet_Sz;
    }
    *lidarPnt->pntNum = pointNum;
}

void conversion(float32_t range_m, float32_t azimuth_deg, fPoint3D_t *lidarPnt,
                uint32_t index)
{
    float32_t rho_m = range_m * vueCosDegree(debugElevationValue[index]);
    float32_t z_m = range_m * vueSinDegree(debugElevationValue[index]);
    float32_t x_m = rho_m * vueSinDegree(azimuth_deg);
    float32_t y_m = rho_m * vueCosDegree(azimuth_deg);
    lidarPnt->x = x_m;
    lidarPnt->y = y_m;
    lidarPnt->z = z_m;
}

static double MazimuthFactor = 0;
void parserInnotekMLIDAR(SensorInfo_t *sInfo, OutputData_t *output)
{
    fColorRGBA_t color = {.a = 1, .b = 0, .g = 1, .r = 0.4};

    UNUSED(output);
    Innotek_MLIDAR *debuge_data;
    int32_t packet_Sz = 6176;
    uint32_t pixelNum = 512;
    float32_t rangeFactor = 0.0046875;
    SensorBuf_t *parserIn = &sInfo->bufInfo.parserIn;
    LidarPoint_t *lidarPnt = sInfo->bufInfo.lidarOutBuffer;
    uint32_t pointNum = 0;
    uint32_t curLoc = 0;
    float32_t range_m = 0;
    float32_t x_m = 0.;
    float32_t y_m = 0.;
    float32_t z_m = 0;
    float32_t rho_m = 0.;
    float32_t azimuth_deg = 0;
    double maxAzimuth = readLidarMaxAzimuth(sInfo->common.sensorName);
    static uint32_t preCustomAz = 0;
    while (curLoc < *parserIn->buf.usingSz)
    {
        if (preCustomAz != maxAzimuth)
        {
            MazimuthFactor = 360. / (maxAzimuth + 1);
        }
        preCustomAz = maxAzimuth;
        debuge_data = (Innotek_MLIDAR *)&parserIn->buf.data[curLoc];
        uint16_t az1 = (debuge_data->Mheader.azimuth1 << 8);
        uint16_t deg = az1 |= debuge_data->Mheader.azimuth2;
        azimuth_deg = deg * MazimuthFactor;

        for (uint32_t i = 0; i < pixelNum; i++)
        {
            range_m = debuge_data->Mbody.evnet1_return0[i] * rangeFactor;
            fPoint3D_t *p = &lidarPnt->pnt[pointNum].coord_m;
            rho_m = range_m * vueCosDegree(debugElevationValue[i]);
            z_m = range_m * vueSinDegree(debugElevationValue[i]);
            x_m = rho_m * vueSinDegree(azimuth_deg);
            y_m = rho_m * vueCosDegree(azimuth_deg);
            p->x = x_m;
            p->y = y_m;
            p->z = z_m;
            calibrate(sInfo->lidar.cal, p);
            lidarPnt->pntInfo[pointNum].radius_m = range_m;
            lidarPnt->pntInfo[pointNum].rho_m = rho_m;
            lidarPnt->pntInfo[pointNum].theta_deg = CalcTheta(p->x, p->y);
            setPCDcolor(&lidarPnt->pnt[pointNum].color_rgba, &color);
            pointNum++;
        }
        curLoc += packet_Sz;
    }
    *lidarPnt->pntNum = pointNum;
}
