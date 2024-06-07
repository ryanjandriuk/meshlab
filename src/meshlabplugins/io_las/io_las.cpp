#include "io_las.h"

QString LASIOPlugin::pluginName() const
{
	return "IOLAS";
}

std::list<FileFormat> LASIOPlugin::importFormats() const
{
	std::list<FileFormat> formatList = {
		FileFormat("|||||||||||||||||||| LAS", tr("LAS"))
	};
	return formatList;
}

std::list<FileFormat> LASIOPlugin::exportFormats() const
{
	return {};
}

void LASIOPlugin::exportMaskCapability(const QString &format, int &capability, int &defaultBits) const
{

}

RichParameterList LASIOPlugin::initPreOpenParameter(const QString &/*format*/) const
{
	return RichParameterList();
}

int readLASHeader(FILE* fp)
{
	printf("LAS HEADER PARSE\n");

	char file_sig[5];
	fread(&file_sig, sizeof(char), 4, fp);
	file_sig[4] = '\0';
	if(strcmp(file_sig, "LASF\0") != 0)
	{
		throw MLException("File not recognized as LASF");
	}

	printf("\tFile Signature: %s\n", file_sig);

	unsigned short file_source_ID;
	fread(&file_source_ID, sizeof(unsigned short), 1, fp);
	printf("\tFile Source ID: %d\n", file_source_ID);

	unsigned short global_encoding;
	fread(&global_encoding, sizeof(unsigned short), 1, fp);
	printf("\tGlobal Encoding: %d\n", global_encoding);

	unsigned long PID_GUID1;
	fread(&PID_GUID1, sizeof(unsigned long), 1, fp);
	printf("\tPID GUID1: %lu\n", PID_GUID1);

	unsigned short PID_GUID2;
	fread(&PID_GUID2, sizeof(unsigned short), 1, fp);
	printf("\tPID GUID2: %d\n", PID_GUID2);

	unsigned short PID_GUID3;
	fread(&PID_GUID3, sizeof(unsigned short), 1, fp);
	printf("\tPID GUID3: %d\n", PID_GUID3);

	char PID_GUID4[9];
	fread(&PID_GUID4, sizeof(char), 8, fp);
	PID_GUID4[8] = '\0';
	printf("\tPID GUID4: %s\n", PID_GUID4);

	unsigned char version_major;
	fread(&version_major, sizeof(unsigned char), 1, fp);
	printf("\tVersion Major: %u\n", version_major);

	unsigned char version_minor;
	fread(&version_minor, sizeof(unsigned char), 1, fp);
	printf("\tVersion Minor: %u\n", version_minor);

	char system_identifier[33];
	fread(&system_identifier, sizeof(char), 32, fp);
	system_identifier[32] = '\0';
	printf("\tSystem Identifier: %s\n", system_identifier);

	char generating_software[33];
	fread(&generating_software, sizeof(char), 32, fp);
	generating_software[32] = '\0';
	printf("\tGenerating Software: %s\n", generating_software);

	unsigned short file_creation_day_of_year;
	fread(&file_creation_day_of_year, sizeof(unsigned short), 1, fp);
	printf("\tFile Creation Day of Year: %d\n", file_creation_day_of_year);

	unsigned short file_creation_year;
	fread(&file_creation_year, sizeof(unsigned short), 1, fp);
	printf("\tFile Creation Year: %d\n", file_creation_year);

	unsigned short header_size;
	fread(&header_size, sizeof(unsigned short), 1, fp);
	printf("\tHeader Size: %d\n", header_size);

	unsigned long offset_to_point_data;
	fread(&offset_to_point_data, sizeof(unsigned long), 1, fp);
	printf("\tOffset to Point Data: %lu\n", offset_to_point_data);

	unsigned long number_of_variable_length_records;
	fread(&number_of_variable_length_records, sizeof(unsigned long), 1, fp);
	printf("\tNumber of Variable Length Records: %lu\n", number_of_variable_length_records);

	unsigned char point_data_record_format;
	fread(&point_data_record_format, sizeof(unsigned char), 1, fp);
	printf("\tPoint Data Record Format: %u\n", point_data_record_format);

	unsigned short point_data_record_length;
	fread(&point_data_record_length, sizeof(unsigned short), 1, fp);
	printf("\tPoint Data Record Length: %d\n", point_data_record_length);

	unsigned long legacy_number_of_point_records;
	fread(&legacy_number_of_point_records, sizeof(unsigned long), 1, fp);
	printf("\tLegacy Number of Point Records: %lu\n", legacy_number_of_point_records);

	unsigned long legacy_number_of_point_by_return[5];
	fread(&legacy_number_of_point_by_return, sizeof(unsigned long), 5, fp);
	printf("\tLegacy Number of Point by Return[0]: %lu\n", legacy_number_of_point_by_return[0]);
	printf("\tLegacy Number of Point by Return[1]: %lu\n", legacy_number_of_point_by_return[1]);
	printf("\tLegacy Number of Point by Return[2]: %lu\n", legacy_number_of_point_by_return[2]);
	printf("\tLegacy Number of Point by Return[3]: %lu\n", legacy_number_of_point_by_return[3]);
	printf("\tLegacy Number of Point by Return[4]: %lu\n", legacy_number_of_point_by_return[4]);


	double x_scale_factor;
	fread(&x_scale_factor, sizeof(double), 1, fp);
	printf("\tX Scale Factor: %f\n", x_scale_factor);

	double y_scale_factor;
	fread(&y_scale_factor, sizeof(double), 1, fp);
	printf("\tY Scale Factor: %f\n", y_scale_factor);

	double z_scale_factor;
	fread(&z_scale_factor, sizeof(double), 1, fp);
	printf("\tZ Scale Factor: %f\n", z_scale_factor);


	double x_offset;
	fread(&x_offset, sizeof(double), 1, fp);
	printf("\tX Offset: %f\n", x_offset);

	double y_offset;
	fread(&y_offset, sizeof(double), 1, fp);
	printf("\tY Offset: %f\n", y_offset);

	double z_offset;
	fread(&z_offset, sizeof(double), 1, fp);
	printf("\tZ Offset: %f\n", z_offset);


	double max_x;
	fread(&max_x, sizeof(double), 1, fp);
	printf("\tMax X: %f\n", max_x);

	double max_y;
	fread(&max_y, sizeof(double), 1, fp);
	printf("\tMax Y: %f\n", max_y);

	double max_z;
	fread(&max_z, sizeof(double), 1, fp);
	printf("\tMax Z: %f\n", max_z);


	double min_x;
	fread(&min_x, sizeof(double), 1, fp);
	printf("\tMin X: %f\n", min_x);

	double min_y;
	fread(&min_y, sizeof(double), 1, fp);
	printf("\tMin Y: %f\n", min_y);

	double min_z;
	fread(&min_z, sizeof(double), 1, fp);
	printf("\tMin Z: %f\n", min_z);

	unsigned long long start_of_waveform_data_packet_record;
	fread(&start_of_waveform_data_packet_record, sizeof(unsigned long long), 1, fp);
	printf("\tStart of Waveform Data Packet Record: %llu\n", start_of_waveform_data_packet_record);

	unsigned long start_of_first_extended_variable_length_record;
	fread(&start_of_first_extended_variable_length_record, sizeof(unsigned long), 1, fp);
	printf("\tStart of First Extended Variable Length Record: %lu\n", start_of_first_extended_variable_length_record);

	unsigned long long number_of_point_records;
	fread(&number_of_point_records, sizeof(unsigned long long), 1, fp);
	printf("\tNumber of Point Records: %llu\n", number_of_point_records);


	return 0;
}

bool parseLAS(const std::string &filename, CMeshO &m) {
	FILE *fp = fopen(filename.c_str(), "rb");
	if (!fp) {
		return false;
	}

	int err = 0;

	err |= readLASHeader(fp);

	return true;
}

void LASIOPlugin::open(const QString &formatName, const QString &fileName, MeshModel &m, int& mask, const RichParameterList &, vcg::CallBackPos *cb)
{
	if(formatName.toUpper() == tr("LAS"))
	{
		//mask |= vcg::tri::io::Mask::IOM_WEDGTEXCOORD;
		//m.enable(mask);
		if (!parseLAS(qUtf8Printable(fileName), m.cm))
			throw MLException("Error while opening LAS file");
	}
	else {
		wrongOpenFormat(formatName);
	}
}

void LASIOPlugin::save(const QString &formatName, const QString &fileName, MeshModel &m, const int mask, const RichParameterList &, vcg::CallBackPos *cb)
{

}

MESHLAB_PLUGIN_NAME_EXPORTER(LASIOPlugin)
