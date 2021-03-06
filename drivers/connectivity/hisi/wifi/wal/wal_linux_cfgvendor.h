/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : wal_linux_cfgvendor.h
  版 本 号   : 初稿
  作    者   : dengwenhua
  生成日期   : 2016年05月10日
  最近修改   :
  功能描述   : Linux cfgvendor 头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2016年05月10日
    作    者   : dengwenhua
    修改内容   : 创建文件

******************************************************************************/

#ifndef __WAL_LINUX_CFGVENDOR_H__
#define __WAL_LINUX_CFGVENDOR_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "oal_ext_if.h"
#include "oal_types.h"


#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_WAL_LINUX_CFGVENDOR_H

#define ATTRIBUTE_U32_LEN                  (OAL_NLMSG_HDRLEN  + 4)
#define VENDOR_ID_OVERHEAD                 ATTRIBUTE_U32_LEN
#define VENDOR_SUBCMD_OVERHEAD             ATTRIBUTE_U32_LEN
#define VENDOR_DATA_OVERHEAD               (OAL_NLMSG_HDRLEN)


#define VENDOR_REPLY_OVERHEAD       (VENDOR_ID_OVERHEAD + \
                                    VENDOR_SUBCMD_OVERHEAD + \
                                    VENDOR_DATA_OVERHEAD)

/* Feature set */
#define VENDOR_DBG_MEMORY_DUMP_SUPPORTED    (1 << (0))  /* Memory dump of FW */

/* firmware event ring, ring id 2 */
#define VENDOR_FW_EVENT_RING_NAME    "fw_event"
#define VENDOR_FW_EVENT_RING_SIZE    (64 * 1024)


/* Feature enums *//* 需和wifi_hal.h中定义保持一致 */
#define WIFI_FEATURE_INFRA              0x0001      /** Basic infrastructure mode */
#define WIFI_FEATURE_INFRA_5G           0x0002      /** Support for 5 GHz Band */
#define WIFI_FEATURE_HOTSPOT            0x0004      /** Support for GAS/ANQP */
#define WIFI_FEATURE_P2P                0x0008      /** Wifi-Direct */
#define WIFI_FEATURE_SOFT_AP            0x0010      /** Soft AP */
#define WIFI_FEATURE_GSCAN              0x0020      /** Google-Scan APIs */
#define WIFI_FEATURE_NAN                0x0040      /** Neighbor Awareness Networking */
#define WIFI_FEATURE_D2D_RTT            0x0080      /** Device-to-device RTT */
#define WIFI_FEATURE_D2AP_RTT           0x0100      /** Device-to-AP RTT */
#define WIFI_FEATURE_BATCH_SCAN         0x0200      /** Batched Scan (legacy) */
#define WIFI_FEATURE_PNO                0x0400      /** Preferred network offload */
#define WIFI_FEATURE_ADDITIONAL_STA     0x0800      /** Support for two STAs */
#define WIFI_FEATURE_TDLS               0x1000      /** Tunnel directed link setup */
#define WIFI_FEATURE_TDLS_OFFCHANNEL    0x2000      /** Support for TDLS off channel */
#define WIFI_FEATURE_EPR                0x4000      /** Enhanced power reporting */
#define WIFI_FEATURE_AP_STA             0x8000      /** Support for AP STA Concurrency */
#define WIFI_FEATURE_LINK_LAYER_STATS  0x10000      /** Link layer stats collection */
#define WIFI_FEATURE_LOGGER            0x20000      /** WiFi Logger */
#define WIFI_FEATURE_HAL_EPNO          0x40000      /** WiFi PNO enhanced */
#define WIFI_FEATURE_RSSI_MONITOR      0x80000      /** RSSI Monitor */
#define WIFI_FEATURE_MKEEP_ALIVE      0x100000      /** WiFi mkeep_alive */

enum gscan_attributes {
    GSCAN_ATTRIBUTE_NUM_BUCKETS = 10,
    GSCAN_ATTRIBUTE_BASE_PERIOD,
    GSCAN_ATTRIBUTE_BUCKETS_BAND,
    GSCAN_ATTRIBUTE_BUCKET_ID,
    GSCAN_ATTRIBUTE_BUCKET_PERIOD,
    GSCAN_ATTRIBUTE_BUCKET_NUM_CHANNELS,
    GSCAN_ATTRIBUTE_BUCKET_CHANNELS,
    GSCAN_ATTRIBUTE_NUM_AP_PER_SCAN,
    GSCAN_ATTRIBUTE_REPORT_THRESHOLD,
    GSCAN_ATTRIBUTE_NUM_SCANS_TO_CACHE,
    GSCAN_ATTRIBUTE_BAND = GSCAN_ATTRIBUTE_BUCKETS_BAND,

    GSCAN_ATTRIBUTE_ENABLE_FEATURE = 20,
    GSCAN_ATTRIBUTE_SCAN_RESULTS_COMPLETE,
    GSCAN_ATTRIBUTE_FLUSH_FEATURE,
    GSCAN_ATTRIBUTE_ENABLE_FULL_SCAN_RESULTS,
    GSCAN_ATTRIBUTE_REPORT_EVENTS,
    /* remaining reserved for additional attributes */
    GSCAN_ATTRIBUTE_NUM_OF_RESULTS = 30,
    GSCAN_ATTRIBUTE_FLUSH_RESULTS,
    GSCAN_ATTRIBUTE_SCAN_RESULTS,                       /* flat array of wifi_scan_result */
    GSCAN_ATTRIBUTE_SCAN_ID,                            /* indicates scan number */
    GSCAN_ATTRIBUTE_SCAN_FLAGS,                         /* indicates if scan was aborted */
    GSCAN_ATTRIBUTE_AP_FLAGS,                           /* flags on significant change event */
    GSCAN_ATTRIBUTE_NUM_CHANNELS,
    GSCAN_ATTRIBUTE_CHANNEL_LIST,

	/* remaining reserved for additional attributes */

    GSCAN_ATTRIBUTE_SSID = 40,
    GSCAN_ATTRIBUTE_BSSID,
    GSCAN_ATTRIBUTE_CHANNEL,
    GSCAN_ATTRIBUTE_RSSI,
    GSCAN_ATTRIBUTE_TIMESTAMP,
    GSCAN_ATTRIBUTE_RTT,
    GSCAN_ATTRIBUTE_RTTSD,

    /* remaining reserved for additional attributes */

    GSCAN_ATTRIBUTE_HOTLIST_BSSIDS = 50,
    GSCAN_ATTRIBUTE_RSSI_LOW,
    GSCAN_ATTRIBUTE_RSSI_HIGH,
    GSCAN_ATTRIBUTE_HOSTLIST_BSSID_ELEM,
    GSCAN_ATTRIBUTE_HOTLIST_FLUSH,

    /* remaining reserved for additional attributes */
    GSCAN_ATTRIBUTE_RSSI_SAMPLE_SIZE = 60,
    GSCAN_ATTRIBUTE_LOST_AP_SAMPLE_SIZE,
    GSCAN_ATTRIBUTE_MIN_BREACHING,
    GSCAN_ATTRIBUTE_SIGNIFICANT_CHANGE_BSSIDS,
    GSCAN_ATTRIBUTE_SIGNIFICANT_CHANGE_FLUSH,

    /* EPNO */
    GSCAN_ATTRIBUTE_EPNO_SSID_LIST = 70,
    GSCAN_ATTRIBUTE_EPNO_SSID,
    GSCAN_ATTRIBUTE_EPNO_SSID_LEN,
    GSCAN_ATTRIBUTE_EPNO_RSSI,
    GSCAN_ATTRIBUTE_EPNO_FLAGS,
    GSCAN_ATTRIBUTE_EPNO_AUTH,
    GSCAN_ATTRIBUTE_EPNO_SSID_NUM,
    GSCAN_ATTRIBUTE_EPNO_FLUSH,

    /* Roam SSID Whitelist and BSSID pref */
    GSCAN_ATTRIBUTE_WHITELIST_SSID = 80,
    GSCAN_ATTRIBUTE_NUM_WL_SSID,
    GSCAN_ATTRIBUTE_WL_SSID_LEN,
    GSCAN_ATTRIBUTE_WL_SSID_FLUSH,
    GSCAN_ATTRIBUTE_WHITELIST_SSID_ELEM,
    GSCAN_ATTRIBUTE_NUM_BSSID,
    GSCAN_ATTRIBUTE_BSSID_PREF_LIST,
    GSCAN_ATTRIBUTE_BSSID_PREF_FLUSH,
    GSCAN_ATTRIBUTE_BSSID_PREF,
    GSCAN_ATTRIBUTE_RSSI_MODIFIER,


    /* Roam cfg */
    GSCAN_ATTRIBUTE_A_BAND_BOOST_THRESHOLD = 90,
    GSCAN_ATTRIBUTE_A_BAND_PENALTY_THRESHOLD,
    GSCAN_ATTRIBUTE_A_BAND_BOOST_FACTOR,
    GSCAN_ATTRIBUTE_A_BAND_PENALTY_FACTOR,
    GSCAN_ATTRIBUTE_A_BAND_MAX_BOOST,
    GSCAN_ATTRIBUTE_LAZY_ROAM_HYSTERESIS,
    GSCAN_ATTRIBUTE_ALERT_ROAM_RSSI_TRIGGER,
    GSCAN_ATTRIBUTE_LAZY_ROAM_ENABLE,

    /* BSSID blacklist */
    GSCAN_ATTRIBUTE_BSSID_BLACKLIST_FLUSH = 100,
    GSCAN_ATTRIBUTE_BLACKLIST_BSSID,

    GSCAN_ATTRIBUTE_ANQPO_HS_LIST = 110,
    GSCAN_ATTRIBUTE_ANQPO_HS_LIST_SIZE,
    GSCAN_ATTRIBUTE_ANQPO_HS_NETWORK_ID,
    GSCAN_ATTRIBUTE_ANQPO_HS_NAI_REALM,
    GSCAN_ATTRIBUTE_ANQPO_HS_ROAM_CONSORTIUM_ID,
    GSCAN_ATTRIBUTE_ANQPO_HS_PLMN,

    /* Adaptive scan attributes */
    GSCAN_ATTRIBUTE_BUCKET_STEP_COUNT = 120,
    GSCAN_ATTRIBUTE_BUCKET_MAX_PERIOD,

    GSCAN_ATTRIBUTE_MAX
};


typedef enum {
    VENDOR_NL80211_SUBCMD_UNSPECIFIED,

    VENDOR_NL80211_SUBCMD_RANGE_START = 0x0001,
    VENDOR_NL80211_SUBCMD_RANGE_END   = 0x0FFF,

    ANDROID_NL80211_SUBCMD_GSCAN_RANGE_START = 0x1000,
    ANDROID_NL80211_SUBCMD_GSCAN_RANGE_END   = 0x10FF,

    ANDROID_NL80211_SUBCMD_RTT_RANGE_START = 0x1100,
    ANDROID_NL80211_SUBCMD_RTT_RANGE_END   = 0x11FF,

    ANDROID_NL80211_SUBCMD_LSTATS_RANGE_START = 0x1200,
    ANDROID_NL80211_SUBCMD_LSTATS_RANGE_END   = 0x12FF,

    ANDROID_NL80211_SUBCMD_TDLS_RANGE_START = 0x1300,
    ANDROID_NL80211_SUBCMD_TDLS_RANGE_END   = 0x13FF,

    ANDROID_NL80211_SUBCMD_DEBUG_RANGE_START = 0x1400,
    ANDROID_NL80211_SUBCMD_DEBUG_RANGE_END  = 0x14FF,

    ANDROID_NL80211_SUBCMD_NBD_RANGE_START = 0x1500,
    ANDROID_NL80211_SUBCMD_NBD_RANGE_END   = 0x15FF,

    ANDROID_NL80211_SUBCMD_WIFI_OFFLOAD_RANGE_START = 0x1600,
    ANDROID_NL80211_SUBCMD_WIFI_OFFLOAD_RANGE_END   = 0x16FF,
} android_vendor_sub_command_enum;


enum wal_vendor_subcmd {
    GSCAN_SUBCMD_GET_CAPABILITIES = ANDROID_NL80211_SUBCMD_GSCAN_RANGE_START,
    GSCAN_SUBCMD_SET_CONFIG,
    GSCAN_SUBCMD_SET_SCAN_CONFIG,
    GSCAN_SUBCMD_ENABLE_GSCAN,
    GSCAN_SUBCMD_GET_SCAN_RESULTS,
    GSCAN_SUBCMD_SCAN_RESULTS,
    GSCAN_SUBCMD_SET_HOTLIST,
    GSCAN_SUBCMD_SET_SIGNIFICANT_CHANGE_CONFIG,
    GSCAN_SUBCMD_ENABLE_FULL_SCAN_RESULTS,
    GSCAN_SUBCMD_GET_CHANNEL_LIST,
    ANDR_WIFI_SUBCMD_GET_FEATURE_SET,
    ANDR_WIFI_SUBCMD_GET_FEATURE_SET_MATRIX,
    ANDR_WIFI_RANDOM_MAC_OUI,
    ANDR_WIFI_NODFS_CHANNELS,
    ANDR_WIFI_SET_COUNTRY,
    GSCAN_SUBCMD_SET_EPNO_SSID,
    WIFI_SUBCMD_SET_SSID_WHITELIST,
    WIFI_SUBCMD_SET_LAZY_ROAM_PARAMS,
    WIFI_SUBCMD_ENABLE_LAZY_ROAM,
    WIFI_SUBCMD_SET_BSSID_PREF,
    WIFI_SUBCMD_SET_BSSID_BLACKLIST,
    GSCAN_SUBCMD_ANQPO_CONFIG,
    WIFI_SUBCMD_SET_RSSI_MONITOR,
    RTT_SUBCMD_SET_CONFIG = ANDROID_NL80211_SUBCMD_RTT_RANGE_START,
    RTT_SUBCMD_CANCEL_CONFIG,
    RTT_SUBCMD_GETCAPABILITY,
    LSTATS_SUBCMD_GET_INFO = ANDROID_NL80211_SUBCMD_LSTATS_RANGE_START,
    DEBUG_START_LOGGING = ANDROID_NL80211_SUBCMD_DEBUG_RANGE_START,
    DEBUG_TRIGGER_MEM_DUMP,
    DEBUG_GET_MEM_DUMP,
    DEBUG_GET_VER,
    DEBUG_GET_RING_STATUS,
    DEBUG_GET_RING_DATA,
    DEBUG_GET_FEATURE,
    DEBUG_RESET_LOGGING,
    WIFI_OFFLOAD_SUBCMD_START_MKEEP_ALIVE = ANDROID_NL80211_SUBCMD_WIFI_OFFLOAD_RANGE_START,
    WIFI_OFFLOAD_SUBCMD_STOP_MKEEP_ALIVE,

    VENDOR_SUBCMD_MAX
};

enum andr_wifi_attr {
	ANDR_WIFI_ATTRIBUTE_NUM_FEATURE_SET,
	ANDR_WIFI_ATTRIBUTE_FEATURE_SET,
	ANDR_WIFI_ATTRIBUTE_RANDOM_MAC_OUI,
	ANDR_WIFI_ATTRIBUTE_NODFS_SET,
	ANDR_WIFI_ATTRIBUTE_COUNTRY
};


typedef enum wal_vendor_event {
    HISI_VENDOR_EVENT_UNSPEC,
    HISI_VENDOR_EVENT_PRIV_STR,
    GOOGLE_GSCAN_SIGNIFICANT_EVENT,
    GOOGLE_GSCAN_GEOFENCE_FOUND_EVENT,
    GOOGLE_GSCAN_BATCH_SCAN_EVENT,
    GOOGLE_SCAN_FULL_RESULTS_EVENT,
    GOOGLE_RTT_COMPLETE_EVENT,
    GOOGLE_SCAN_COMPLETE_EVENT,
    GOOGLE_GSCAN_GEOFENCE_LOST_EVENT,
    GOOGLE_SCAN_EPNO_EVENT,
    GOOGLE_DEBUG_RING_EVENT,
    GOOGLE_FW_DUMP_EVENT,
    GOOGLE_PNO_HOTSPOT_FOUND_EVENT,
    GOOGLE_RSSI_MONITOR_EVENT,
    GOOGLE_MKEEP_ALIVE_EVENT
} wal_vendor_event_enum;

enum wal_vendor_debug_attributes {
    DEBUG_ATTRIBUTE_GET_DRIVER,
    DEBUG_ATTRIBUTE_GET_FW,
    DEBUG_ATTRIBUTE_RING_ID,
    DEBUG_ATTRIBUTE_RING_NAME,
    DEBUG_ATTRIBUTE_RING_FLAGS,
    DEBUG_ATTRIBUTE_LOG_LEVEL,
    DEBUG_ATTRIBUTE_LOG_TIME_INTVAL,
    DEBUG_ATTRIBUTE_LOG_MIN_DATA_SIZE,
    DEBUG_ATTRIBUTE_FW_DUMP_LEN,
    DEBUG_ATTRIBUTE_FW_DUMP_DATA,
    DEBUG_ATTRIBUTE_RING_DATA,
    DEBUG_ATTRIBUTE_RING_STATUS,
    DEBUG_ATTRIBUTE_RING_NUM
};

enum {
    DEBUG_RING_ID_INVALID	= 0,
    FW_VERBOSE_RING_ID,
    FW_EVENT_RING_ID,
    DHD_EVENT_RING_ID,
    /* add new id here */
    DEBUG_RING_ID_MAX
};

typedef struct debug_ring_status_st {
    oal_uint8 uc_name[32];
    oal_uint32 ul_flags;
    oal_int ring_id; /* unique integer representing the ring */
    /* total memory size allocated for the buffer */
    oal_uint32 ul_ring_buffer_byte_size;
    oal_uint32 ul_verbose_level;
    /* number of bytes that was written to the buffer by driver */
    oal_uint32 ul_written_bytes;
    /* number of bytes that was read from the buffer by user land */
    oal_uint32 ul_read_bytes;
    /* number of records that was read from the buffer by user land */
    oal_uint32 ul_written_records;
} debug_ring_status_st;

extern oal_void wal_cfgvendor_init(oal_wiphy_stru *wiphy);
extern oal_void wal_cfgvendor_deinit(oal_wiphy_stru *wiphy);

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of wal_linux_cfgvendor.h */
