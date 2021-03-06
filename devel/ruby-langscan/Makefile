# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	langscan
PORTVERSION=	1.2.20070115
CATEGORIES=	devel ruby
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Program analyzer for source code search engine

LICENSE=	GPLv2

RUN_DEPENDS=	p5-PPI>=0:${PORTSDIR}/textproc/p5-PPI
BUILD_DEPENDS=	flex>=2.5.31:${PORTSDIR}/textproc/flex

USES=		perl5
USE_AUTOTOOLS=	aclocal:env automake:env autoconf:env
USE_RUBY=	yes
USE_PERL5=	run
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
HAS_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

PORTDOCS=	ChangeLog NEWS README
DOCSDIR=	${RUBY_MODDOCDIR}

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/ruby-${PORTNAME}/options

CFLAGS+=	-fPIC

CFLAGS+=	-I${LOCALBASE}/include/ruby-${RUBY_VER} \
		-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
PLIST_SUB+=	RIPPER="@comment "

post-patch:
	${REINPLACE_CMD} "s|\(flex --version\)|${LOCALBASE}/bin/\1|" ${WRKSRC}/autogen.sh
	${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${REINPLACE_CMD} "s|flex|${LOCALBASE}/bin/flex|"

pre-configure:
	cd ${CONFIGURE_WRKSRC}; ${SH} autogen.sh

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/${PORTNAME}/ocaml/camlexer
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

# Workaround bsd.ocaml.mk to fix packaging
add-plist-post:
	@${DO_NADA}

x-generate-plist:
	${ECHO} %%RUBY_SITELIBDIR%%/langscan.rb > pkg-plist.new
	${FIND} ${RUBY_SITEARCHLIBDIR}/${PORTNAME} -type f | ${SORT} | ${SED} -e 's,${RUBY_SITEARCHLIBDIR},%%RUBY_SITEARCHLIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITEARCHLIBDIR}/${PORTNAME} -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITEARCHLIBDIR},@dirrm %%RUBY_SITEARCHLIBDIR%%,' >> pkg-plist.new

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 2.1
BROKEN=		Does not build with Ruby 2.1
.endif

.include <bsd.port.post.mk>
