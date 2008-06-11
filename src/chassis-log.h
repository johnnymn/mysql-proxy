/* Copyright (C) 2007, 2008 MySQL AB */ 

#ifndef _CHASSIS_LOG_H_
#define _CHASSIS_LOG_H_

#include <glib.h>
#ifdef _WIN32
#include <windows.h>
#endif

#include "chassis-exports.h"

typedef struct {
	GLogLevelFlags min_lvl;

	gchar *log_filename;
	gint log_file_fd;

	gboolean use_syslog;

#ifdef _WIN32
	HANDLE event_source_handle;
	gboolean use_windows_applog;
#endif
	gboolean rotate_logs;

	GString *log_ts_str;

	GString *last_msg;
	time_t   last_msg_ts;
	guint    last_msg_count;
} chassis_log;


CHASSIS_API chassis_log *chassis_log_init(void);
CHASSIS_API int chassis_log_set_level(chassis_log *log, const gchar *level);
CHASSIS_API void chassis_log_free(chassis_log *log);
CHASSIS_API int chassis_log_open(chassis_log *log);
CHASSIS_API void chassis_log_func(const gchar *log_domain, GLogLevelFlags log_level, const gchar *message, gpointer user_data);
CHASSIS_API void chassis_log_set_logrotate(chassis_log *log);

#endif