# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	sagasu
PORTVERSION=	2.0.12
CATEGORIES=	textproc gnome
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME tool to find strings in a set of files

LICENSE=	GPLv2 # (or later)

USES=		pathfix pkgconfig gettext gmake
USE_GNOME=	gnomehier libgnomeui
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE= DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/util.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS INSTALL NEWS README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
