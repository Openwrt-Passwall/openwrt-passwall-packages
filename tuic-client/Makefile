# SPDX-License-Identifier: GPL-2.0-or-later
#
# Copyright (C) 2021 ImmortalWrt.org

include $(TOPDIR)/rules.mk

PKG_NAME:=tuic-client
PKG_VERSION:=1.8.5
PKG_RELEASE:=1

PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Tianling Shen <cnsztl@immortalwrt.org>

include $(INCLUDE_DIR)/package.mk

ifeq ($(ARCH),aarch64)
	TUIC_ARCH:=tuic-client-aarch64-linux-musl
	PKG_HASH:=6edf92d25b1883e3a38252d9ac115b18b65411135eb448020a5515841e4dca9a
else ifeq ($(ARCH),arm)
# Referred to golang/golang-values.mk
	ARM_CPU_FEATURES:=$(word 2,$(subst +,$(space),$(call qstrip,$(CONFIG_CPU_TYPE))))
	ifeq ($(ARM_CPU_FEATURES),)
		TUIC_ARCH:=tuic-client-armv7-linux-musl
		PKG_HASH:=a9fa74ec8b770cdbcf776c29c4c9cef207c79cd0dc5860eb6a7d88ab00574ee8
	else
		TUIC_ARCH:=tuic-client-armv7-linux-muslhf
		PKG_HASH:=8a1b1f563a5c29755d9ee3fb1f31af5215c6379b77c9c3b73d83dc58bf0594ab
	endif
else ifeq ($(ARCH),i386)
	TUIC_ARCH:=tuic-client-i686-linux-musl
	PKG_HASH:=a88ecbebda2f0f9ba634b930253fde4e5ea7cccb6744f8dd74b84ed50c142780
else ifeq ($(ARCH),x86_64)
	TUIC_ARCH:=tuic-client-x86_64-linux-musl
	PKG_HASH:=0db527a41b955894cac116bdec273d1ab7612ea4bfe7aac3a2819bf77c399f0a
# Set the default value to make OpenWrt Package Checker happy
else
  PKG_SOURCE:=dummy
  PKG_HASH:=dummy
endif

define Download/tuic-client
	URL:=https://github.com/Itsusinn/tuic/releases/download/v$(PKG_VERSION)/
	URL_FILE:=$(TUIC_ARCH)
	FILE:=$(TUIC_ARCH)-$(PKG_VERSION)
	HASH:=$(PKG_HASH)
endef

$(eval $(call Download,tuic-client))

define Package/tuic-client
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	TITLE:=Delicately-TUICed 0-RTT proxy protocol
	URL:=https://github.com/Itsusinn/tuic
	DEPENDS:=@USE_MUSL @(aarch64||arm_v7||i386||x86_64) @!(TARGET_x86_geode||TARGET_x86_legacy)
endef

define Build/Compile
endef

define Package/tuic-client/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(DL_DIR)/$(TUIC_ARCH)-$(PKG_VERSION) $(1)/usr/bin/tuic-client
endef

$(eval $(call BuildPackage,tuic-client))
