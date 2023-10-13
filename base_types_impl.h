#ifndef BASE_TYPES_IMPL_H
#define BASE_TYPES_IMPL_H

#include <stdint.h>
#include <vector>
#include <deque>
#include <string>
//#include <boost/date_time.hpp>

typedef uint8_t t_buf_val;
typedef std::vector<t_buf_val> BufferType;
typedef std::vector<BufferType> ByteBuffers;
typedef BufferType t_Buffer;
typedef std::deque<uint8_t> BidiBuffer;
typedef uint32_t t_CrcSum; // обязательно беззнаковый, иначе получим вопросы знакорасширения типов.
typedef std::vector<int8_t> Int8Vector;
typedef std::vector<uint16_t> Uint16Vector;
typedef std::vector<uint32_t> Uint32Vector;
typedef std::vector<uint64_t> Uint64Vector;
typedef std::vector<int64_t> Int64Vector;
typedef std::vector<std::string> StringsVector;
typedef std::vector<float> FloatVector;
typedef std::vector<double> DoubleVector;
typedef std::vector<int> IntVector;
//typedef boost::posix_time::ptime t_timeutc; ///< абсолютное системное время в UTC
//typedef boost::posix_time::ptime t_timewall; ///< настенное время (время в локальной TimeZone прибора)
typedef long long t_timeutc; ///< абсолютное системное время в UTC
typedef long long t_timewall; ///< настенное время (время в локальной TimeZone прибора)

#endif // BASE_TYPES_IMPL_H
