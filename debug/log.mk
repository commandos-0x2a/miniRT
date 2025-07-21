LOG_MSG=ft_fprintf(2, "%s:%d %s\n", __FILE__, __LINE__, msg);

CPPCLAGS += -D'LOG_DEBUG(msg)=LOG_MSG(msg)'
CPPCLAGS += -D'LOG_INFO(msg)=LOG_MSG(msg)'
CPPCLAGS += -D'LOG_WARN(msg)=LOG_MSG(msg)'
CPPCLAGS += -D'LOG_ERROR(msg)=LOG_MSG(msg)'
CPPCLAGS += -D'LOG_FATAL(msg)=LOG_MSG(msg)'
