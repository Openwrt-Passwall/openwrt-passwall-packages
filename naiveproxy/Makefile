include $(TOPDIR)/rules.mk

PKG_NAME:=naiveproxy
PKG_VERSION:=148.0.7778.96
PKG_RELEASE:=2

ARCH_PREBUILT:=$(ARCH_PACKAGES)

# intel 80386 & riscv64 & cortex-a76
ifeq ($(ARCH_PREBUILT),aarch64_cortex-a76)
  ARCH_PREBUILT:=aarch64_generic
else ifeq ($(ARCH_PREBUILT),i386_pentium-mmx)
  ARCH_PREBUILT:=x86
else ifeq ($(ARCH_PREBUILT),i386_pentium4)
  ARCH_PREBUILT:=x86
else ifeq ($(ARCH_PREBUILT),mipsel_24kc_24kf)
  ARCH_PREBUILT:=mipsel_24kc
else ifeq ($(ARCH_PREBUILT),mipsel_74kc)
  ARCH_PREBUILT:=mipsel_24kc
else ifeq ($(ARCH_PREBUILT),riscv64_riscv64)
  ARCH_PREBUILT:=riscv64
endif

PKG_SOURCE:=naiveproxy-v$(PKG_VERSION)-$(PKG_RELEASE)-openwrt-$(ARCH_PREBUILT).tar.xz
PKG_SOURCE_URL:=https://github.com/klzgrad/naiveproxy/releases/download/v$(PKG_VERSION)-$(PKG_RELEASE)/

ifeq ($(ARCH_PREBUILT),aarch64_cortex-a53)
  PKG_HASH:=d7a6526fdf93b54cfb45416ec79e2da0679be9ada4a43b75829e6d4b0619b84c
else ifeq ($(ARCH_PREBUILT),aarch64_cortex-a72)
  PKG_HASH:=2aa8f7b3f322e3880455cfba89acdd70e18845fd002af40bb74e81562e5f53d7
else ifeq ($(ARCH_PREBUILT),aarch64_generic)
  PKG_HASH:=83248fe3c4e228a3db4e0e4fce983448ceb1e2024ad313217b9fb1c2ba632d20
else ifeq ($(ARCH_PREBUILT),arm_arm1176jzf-s_vfp)
  PKG_HASH:=c65a7fa8688418cef0f690ff478cfaf6df80a40e3b796e2f141ccd32deb4f19e
else ifeq ($(ARCH_PREBUILT),arm_arm926ej-s)
  PKG_HASH:=69311d3b91ac79c0c49e8f84a40946888456d76e5258a66fcb5dff7837278006
else ifeq ($(ARCH_PREBUILT),arm_cortex-a15_neon-vfpv4)
  PKG_HASH:=0f7d457c92c66c8d5b9943ed0e860713d399179083b0c4cef669f0aa79569025
else ifeq ($(ARCH_PREBUILT),arm_cortex-a5_vfpv4)
  PKG_HASH:=5d66fccf9b32adcbb342f8f1e775cebe7aba930b4606896f29c93a7b0e6fe2ab
else ifeq ($(ARCH_PREBUILT),arm_cortex-a7)
  PKG_HASH:=52dcb3502658ed96bb4e571ea7ce43deef50c922ceb0af8a68bfa7ee3e71ec8b
else ifeq ($(ARCH_PREBUILT),arm_cortex-a7_neon-vfpv4)
  PKG_HASH:=e0059811b2bbf5c30aa528c3e744a55c233a3309e47804352c81506f1a2714a5
else ifeq ($(ARCH_PREBUILT),arm_cortex-a7_vfpv4)
  PKG_HASH:=e63e35f1fbbd3620f845781e4b876a21c05bc1bc37edd8776433807cf30374e3
else ifeq ($(ARCH_PREBUILT),arm_cortex-a8_vfpv3)
  PKG_HASH:=cd20dcc2965a83a8162ebe65e4714394293b5c289661ccd6beeecf60d211ce05
else ifeq ($(ARCH_PREBUILT),arm_cortex-a9)
  PKG_HASH:=eec65d9b15a5179d9c93748a75fc7c91ce433acb450278a5de376ed3bada92f8
else ifeq ($(ARCH_PREBUILT),arm_cortex-a9_neon)
  PKG_HASH:=d5cfb20a01829c84a23696bf1e29512554fa19793cb74da010dfab752f44670f
else ifeq ($(ARCH_PREBUILT),arm_cortex-a9_vfpv3-d16)
  PKG_HASH:=5ad7354d0a4abab386194d9def958884f6afb38e9657dd1efab1f5aaac3e0c76
else ifeq ($(ARCH_PREBUILT),arm_mpcore)
  PKG_HASH:=dbad3e897bc5ca56dea018bb54ce15f8eae28a54e24210d8b2b1bba54e6e56db
else ifeq ($(ARCH_PREBUILT),arm_xscale)
  PKG_HASH:=2000c564e12ea151b4f1aacea0cfa7a3fae8c182dbbaf219b0f7b5f74e8d9d15
else ifeq ($(ARCH_PREBUILT),mipsel_24kc)
  PKG_HASH:=e3d63e0224974ccdc2c68051a406f02ef52d0a8d3d6f5bf1895d3d951780474d
else ifeq ($(ARCH_PREBUILT),mipsel_mips32)
  PKG_HASH:=4f27add197b13ff60f7c375550dd2f067960079cb46de79dc2f383abae4a158d
else ifeq ($(ARCH_PREBUILT),riscv64)
  PKG_HASH:=7aeb8c791f8eac04dcc6bddb079e3d9f7e0d19fbe9305020f358fc43f15a6b6e
else ifeq ($(ARCH_PREBUILT),x86)
  PKG_HASH:=bb08670031d23b5ddfa161c9dfba6700b61040ac0946057588d24d55ded75fe8
else ifeq ($(ARCH_PREBUILT),x86_64)
  PKG_HASH:=9922c835a080a340fcf166581f77a3759dad0f4967fb6a5fcc8cb41e817f82df
else
  PKG_HASH:=dummy
endif

PKG_LICENSE:=BSD 3-Clause
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=sbwml <admin@cooluc.com>

PKG_BUILD_DIR:=$(BUILD_DIR)/naiveproxy-v$(PKG_VERSION)-$(PKG_RELEASE)-openwrt-$(ARCH_PACKAGES)

include $(INCLUDE_DIR)/package.mk

define Package/naiveproxy
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web Servers/Proxies
  TITLE:=Make a fortune quietly
  URL:=https://github.com/klzgrad/naiveproxy
  DEPENDS:=@(aarch64||arm||i386||mipsel||riscv64||x86_64) +libatomic
endef

define Package/naiveproxy/description
  NaïveProxy uses Chrome's network stack to camouflage traffic with strong
  censorship resistance and low detectability. Reusing Chrome's stack also
  ensures best practices in performance and security.
endef

define Package/naiveproxy/conffiles
/etc/config/naiveproxy
endef

define Build/Prepare
	$(TAR) --strip-components=1 -C $(PKG_BUILD_DIR) -xJf $(DL_DIR)/naiveproxy-v$(PKG_VERSION)-$(PKG_RELEASE)-openwrt-$(ARCH_PREBUILT).tar.xz
endef

define Build/Compile
endef

define Package/naiveproxy/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/naive $(1)/usr/bin/naive
	$(INSTALL_DIR) $(1)/etc/config $(1)/etc/init.d
	$(INSTALL_CONF) $(CURDIR)/files/naiveproxy.config $(1)/etc/config/naiveproxy
	$(INSTALL_BIN) $(CURDIR)/files/naiveproxy.init $(1)/etc/init.d/naiveproxy
endef

$(eval $(call BuildPackage,naiveproxy))
