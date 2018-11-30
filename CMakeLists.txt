cmake_minimum_required(VERSION 2.8.12)

project(libjpeg)

#set (CMAKE_CXX_STANDARD 11)

include_directories(.)

add_library(jpegbox STATIC
	boxes/alphabox.cpp
	boxes/box.cpp
	boxes/checksumbox.cpp
	boxes/colortrafobox.cpp
	boxes/databox.cpp
	boxes/dctbox.cpp
	boxes/filetypebox.cpp
	boxes/floattonemappingbox.cpp
	boxes/floattransformationbox.cpp
	boxes/inversetonemappingbox.cpp
	boxes/lineartransformationbox.cpp
	boxes/matrixbox.cpp
	boxes/mergingspecbox.cpp
	boxes/namespace.cpp
	boxes/nonlineartrafobox.cpp
	boxes/outputconversionbox.cpp
	boxes/parametrictonemappingbox.cpp
	boxes/refinementspecbox.cpp
	boxes/superbox.cpp
	boxes/tonemapperbox.cpp)

add_library(jpegcodestream STATIC
	codestream/aclosslessscan.cpp
	codestream/acrefinementscan.cpp
	codestream/acsequentialscan.cpp
	codestream/decoder.cpp
	codestream/encoder.cpp
	codestream/entropyparser.cpp
	codestream/image.cpp
	codestream/jpeglsscan.cpp
	codestream/lineinterleavedlsscan.cpp
	codestream/losslessscan.cpp
	codestream/predictivescan.cpp
	codestream/predictorbase.cpp
	codestream/predictor.cpp
	codestream/rectanglerequest.cpp
	codestream/refinementscan.cpp
	codestream/sampleinterleavedlsscan.cpp
	codestream/sequentialscan.cpp
	codestream/singlecomponentlsscan.cpp
	codestream/tables.cpp)

add_library(jpegcoding STATIC
	coding/actemplate.cpp
	coding/arithmetictemplate.cpp
	coding/arthdeco.cpp
	coding/blockrow.cpp
	coding/decodertemplate.cpp
	coding/huffmancoder.cpp
	coding/huffmandecoder.cpp
	coding/huffmanstatistics.cpp
	coding/huffmantemplate.cpp
	coding/qmcoder.cpp
	coding/quantizedrow.cpp)

add_library(jpegcolortrafo STATIC
	colortrafo/colortrafo.cpp
	colortrafo/colortransformerfactory.cpp
	colortrafo/floattrafo.cpp
	colortrafo/integertrafo.cpp
	colortrafo/lslosslesstrafo.cpp
	colortrafo/multiplicationtrafo.cpp
	colortrafo/trivialtrafo.cpp
	colortrafo/ycbcrtrafo.cpp)

add_library(jpegcontrol STATIC
	control/bitmapctrl.cpp
	control/blockbitmaprequester.cpp
	control/blockbuffer.cpp
	control/blockctrl.cpp
	control/blocklineadapter.cpp
	control/bufferctrl.cpp
	control/hierarchicalbitmaprequester.cpp
	control/lineadapter.cpp
	control/linebitmaprequester.cpp
	control/linebuffer.cpp
	control/linelineadapter.cpp
	control/linemerger.cpp
	control/residualblockhelper.cpp
	control/residualbuffer.cpp)

add_library(jpegdct STATIC
	dct/dct.cpp
	dct/deringing.cpp
	dct/idct.cpp
	dct/liftingdct.cpp)

add_library(jpeginterface STATIC
	interface/bitmaphook.cpp
	interface/imagebitmap.cpp
	interface/jpeg.cpp
	interface/tagitem.cpp)

add_library(jpegio STATIC
	io/bitstream.cpp
	io/bytestream.cpp
	io/checksumadapter.cpp
	io/decoderstream.cpp
	io/iostream.cpp
	io/memorystream.cpp
	io/randomaccessstream.cpp
	io/staticstream.cpp)

add_library(jpegmarker STATIC
	marker/actable.cpp
	marker/adobemarker.cpp
	marker/component.cpp
	marker/exifmarker.cpp
	marker/frame.cpp
	marker/huffmantable.cpp
	marker/jfifmarker.cpp
	marker/lscolortrafo.cpp
	marker/quantization.cpp
	marker/quantizationtable.cpp
	marker/restartintervalmarker.cpp
	marker/scan.cpp
	marker/scantypes.cpp
	marker/thresholds.cpp)

add_library(jpegtools STATIC
	tools/environment.cpp
	tools/numerics.cpp)

add_library(jpegupsampling STATIC
	upsampling/cositedupsampler.cpp
	upsampling/downsamplerbase.cpp
	upsampling/downsampler.cpp
	upsampling/interdownsampler.cpp
	upsampling/upsamplerbase.cpp
	upsampling/upsampler.cpp)

add_executable(jpeg
	cmd/bitmaphook.cpp
	cmd/defaulttmoc.cpp
	cmd/encodea.cpp
	cmd/encodeb.cpp
	cmd/encodec.cpp
	cmd/filehook.cpp
	cmd/iohelpers.cpp
	cmd/main.cpp
	cmd/reconstruct.cpp
	cmd/tmo.cpp)

target_link_libraries(jpeg
	-Wl,--start-group
	jpegbox
	jpegcodestream
	jpegcoding
	jpegcolortrafo
	jpegcontrol
	jpegdct
	jpeginterface
	jpegio
	jpegmarker
	jpegtools
	jpegupsampling
	-Wl,--end-group)
