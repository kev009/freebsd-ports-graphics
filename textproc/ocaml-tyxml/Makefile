# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	tyxml
PORTVERSION=	2.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://ocsigen.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml XML typing library

LICENSE=	LGPL21_SSLEX
LICENSE_NAME=	Lesser GPL 2.1 with a special OpenSSL exception clause
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${SA_DIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net
RUN_DEPENDS=	${SA_DIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USES=			gmake
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

SA_DIR=			${LOCALBASE}/${OCAML_SITELIBDIR}
MAKE_ENV+=		INSTALLDIR="${STAGEDIR}${SA_DIR}"

.include <bsd.port.mk>
