
#ifndef __PARSER_INNOTEK_H
#define __PARSER_INNOTEK_H

#ifdef __cplusplus
extern "C"
{
#endif

    extern float32_t g_afJetColorArray[256 * 3];
    typedef struct InnoteckMR_HEAD
    {
        uint8_t syncword;
        uint8_t version;
        uint8_t mode;
        uint8_t num_returns;
        uint16_t numpixels;
        uint16_t numcolumns;
        uint32_t frame_sequence_number;
        uint32_t column_azimuth_span;
    } InootekMR_Header;

    typedef struct InnoteckMR_Time
    {
        uint64_t col[4];
    } InootekMR_TimeStamp;

    typedef struct InnoteckMR_inten
    {
        uint8_t Inten_col1_return0[128];
        uint8_t Inten_col1_return1[128];
        uint8_t Inten_col2_return0[128];
        uint8_t Inten_col2_return1[128];
        uint8_t Inten_col3_return0[128];
        uint8_t Inten_col3_return1[128];
        uint8_t Inten_col4_return0[128];
        uint8_t Inten_col4_return1[128];
    } InootekMR_intensities;

    typedef struct InnoteckMR_ragne
    {
        uint16_t return_return0[512];
        uint16_t return_return1[512];
    } InootekMR_range;
    typedef struct
    {
        InootekMR_TimeStamp timestamp;
        uint32_t azimuth_raw[4];
        InootekMR_range range;
        InootekMR_intensities intensities;
        uint8_t confidences[1024];
        uint32_t noise[512];
        uint32_t avalanches[256];
        uint32_t trials[256];
        /* data */
    } InnoteckMR_Body;

    typedef struct InnoteckMR
    {
        InootekMR_Header header;
        InnoteckMR_Body body;
        uint32_t reserve;
    } __attribute__((packed, aligned(4))) InnoteckMR_Packet;

    typedef struct InnoteckDebug
    {
        uint16_t pixel[3072];
    } InnoteckDebug_type2_body;

    typedef struct
    {
        uint8_t syncword;
        uint8_t version;
        uint8_t mode;
        uint8_t returns;
        uint16_t hight_pixel;
        uint16_t width_pixel;
        uint64_t timestamp_ns;
        uint16_t azimuth;
        uint16_t elevation_rad;
        uint16_t packet_number;
        uint16_t bin_width_ps;
        uint16_t signal_dly_bins;
        uint16_t gate_dly_bins;
        uint16_t gate_width_bins;
        uint16_t rearm_dly_bins;
    } InnoMR_D_Header;
    typedef struct
    {
        uint8_t syncword;
        uint8_t version;
        uint8_t mode;
        uint8_t returns;
        uint16_t hight_pixel;
        uint16_t width_pixel;
        uint64_t timestamp_ns;
        uint8_t azimuth1;
        uint8_t azimuth2;
        uint16_t elevation_rad;
        uint16_t packet_number;
        uint16_t bin_width_ps;
        uint16_t signal_dly_bins;
        uint16_t gate_dly_bins;
        uint16_t gate_width_bins;
        uint16_t rearm_dly_bins;
    } InnoM_D_Header;

    typedef struct
    {
        uint16_t evnet1_return0[512];
        uint16_t evnet1_return1[512];
        uint16_t evnet1_return2[512];
        uint16_t evnet2_return0[512];
        uint16_t evnet2_return1[512];
        uint16_t evnet2_return2[512];
    } InnotekM;
    typedef struct
    {
        InnoMR_D_Header header;
        InnoteckDebug_type2_body body;
    } InnotekMR_Debug;

    typedef struct
    {
        InnoM_D_Header Mheader;
        InnotekM Mbody;
    } Innotek_MLIDAR;

    void parserInnotekArgoMR_Debug(SensorInfo_t *sInfo, OutputData_t *output);
    void parserInnotekArgoLR(SensorInfo_t *sInfo, OutputData_t *output);
    void parserInnotekArgoMR(SensorInfo_t *sInfo, OutputData_t *output);
    void parserInnotekMLIDAR(SensorInfo_t *sInfo, OutputData_t *output);

#ifdef __cplusplus
}
#endif

#endif // __PARSER_INNOTEK_H