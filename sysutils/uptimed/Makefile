# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	uptimed
PORTVERSION=	0.3.17
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://podgorny.cz/uptimed/releases/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uptime daemon

LICENSE=	GPLv2

USES=		gmake libtool tar:bzip2
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
ACLOCAL_ARGS=	# empty
AUTOMAKE_ARGS=	--copy --add-missing --foreign
USE_LDCONFIG=	yes

USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/sendmail|/usr/sbin/sendmail| ; \
		 s|/var/run/uptimed|/var/run/uptimed.pid|' \
		${WRKSRC}/etc/uptimed.conf-dist
	 @${REINPLACE_CMD} -e \
	 	's|/etc/uprecords-cgi/|${PREFIX}/www/cgi-bin/|' \
	 	${WRKSRC}/src/uprecords.c

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/uprecords \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.cgi
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/uprecords.conf \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/uprecords.header \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.header.sample
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/uprecords.footer \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.footer.sample
	@${MKDIR} ${STAGEDIR}/var/spool/uptimed

.include <bsd.port.mk>
