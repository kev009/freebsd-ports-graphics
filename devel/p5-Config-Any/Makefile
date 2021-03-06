# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-Any
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load class configuration data from a number of file formats

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-General>=2.47:${PORTSDIR}/devel/p5-Config-General
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	INI JSON XML YAML
OPTIONS_DEFAULT=INI JSON XML YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINI}
BUILD_DEPENDS+=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny
RUN_DEPENDS+=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny
.endif

.if ${PORT_OPTIONS:MJSON}
BUILD_DEPENDS+=	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS
RUN_DEPENDS+=	p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS
.endif

.if ${PORT_OPTIONS:MXML}
BUILD_DEPENDS+=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS+=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
.endif

.if ${PORT_OPTIONS:MYAML}
BUILD_DEPENDS+=	p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML
RUN_DEPENDS+=	p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502000
# Module::Pluggable was first released with perl v5.8.9 and removed from v5.19.0
RUN_DEPENDS+=	p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
BUILD_DEPENDS+=	p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
