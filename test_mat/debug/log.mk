LOG_MSG=ft_fprintf(2, "%s:%d %s\n", __FILE__, __LINE__, msg);

CPPFLAGS += -D'LOG_DEBUG(msg)=$(LOG_MSG)'
CPPFLAGS += -D'LOG_INFO(msg)=$(LOG_MSG)'
CPPFLAGS += -D'LOG_WARN(msg)=$(LOG_MSG)'
CPPFLAGS += -D'LOG_ERROR(msg)=$(LOG_MSG)'
CPPFLAGS += -D'LOG_FATAL(msg)=$(LOG_MSG)'
