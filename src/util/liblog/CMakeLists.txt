SET(liblog_SRC
	Logger
	Ostream_logger
	File_logger
	Formatter
	Raw_formatter
	Datetime_formatter
	Msg
)

add_library(log STATIC ${liblog_SRC})
