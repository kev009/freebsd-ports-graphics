# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sk1libs
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Set of python libraries for sK1 Project

LIB_DEPENDS=	liblcms.so:${PORTSDIR}/graphics/lcms \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

PROJECTHOST=	uniconvertor

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_BUILD_TARGET=build_ext
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib \
			-I${LOCALBASE}/include:${LOCALBASE}/include/freetype2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/src/utils/fs.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/sk1libs/ft2engine/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sk1libs/pycms/*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/sk1libs/imaging/*.so

.include <bsd.port.mk>
