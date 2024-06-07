#ifndef LASIOPLUGIN_H
#define LASIOPLUGIN_H

#include <QObject>

#include <common/plugins/interfaces/io_plugin.h>
#include <common/ml_document/mesh_model.h>

class LASIOPlugin : public QObject, public IOPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(IO_PLUGIN_IID)
	Q_INTERFACES(IOPlugin)


public:
	QString pluginName() const;
	std::list<FileFormat> importFormats() const;
	std::list<FileFormat> exportFormats() const;
	virtual void exportMaskCapability(const QString &format, int &capability, int &defaultBits) const;
	virtual RichParameterList initPreOpenParameter(const QString &/*format*/) const;

	void open(const QString &formatName, const QString &fileName, MeshModel &m, int& mask, const RichParameterList &, vcg::CallBackPos *cb=0);
	void save(const QString &formatName, const QString &fileName, MeshModel &m, const int mask, const RichParameterList &, vcg::CallBackPos *cb);
};

#endif
