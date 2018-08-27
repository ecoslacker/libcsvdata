#ifndef CSVDATA_H
#define CSVDATA_H

#if defined (WIN32) && defined (BUILD_SHARED_LIBS)
	#if defined (_MSC_VER)
		#pragma warning(disable: 4251)
	#endif
	
	#if defined(CsvData_EXPORT)
		#define CSVDATA_EXPORT __declspec(dllexport)
	#else
		#define CSVDATA_EXPORT __declspec(dllexport)
	#endif
#else
	#define CSVDATA_EXPORT
#endif

#include <vector>
#include <string>

class CSVDATA_EXPORT CsvData
{

public:
    CsvData();
    static bool parseFromFile(const std::string &filename, std::vector< std::vector< std::string> > &data, char delimiter=',');
    static std::vector< std::vector< std::string> > parse(const std::string &string_content, char delimiter=',');
    static bool write(const std::string &filename, std::vector< std::vector< std::string> > &data, std::string delimiter=",");
    static bool write(const std::string &filename, std::vector< std::vector<double> > &data, std::string delimiter=",");
};

#endif // CSVDATA_H