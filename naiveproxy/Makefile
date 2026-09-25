include $(TOPDIR)/rules.mk

PKG_NAME:=naiveproxy
PKG_VERSION:=154.0.8037.49
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
  PKG_HASH:=48d383edb5da670de89d500d4b7380e17977942f80db167860d7194717be3951
else ifeq ($(ARCH_PREBUILT),aarch64_cortex-a72)
  PKG_HASH:=6b0362f2e2eb267803064a958229f3d3451ead6bde2b5a7acafe349ba741cbcd
else ifeq ($(ARCH_PREBUILT),aarch64_generic)
  PKG_HASH:=0c071e7632d6df2031661ec92956fe303d31eae9f2f7343c78b74f632b45cab3
else ifeq ($(ARCH_PREBUILT),arm_arm1176jzf-s_vfp)
  PKG_HASH:=9aba6f3472478b206430afef7eb005de6b957fb893432f7d8b9100012310117b
else ifeq ($(ARCH_PREBUILT),arm_arm926ej-s)
  PKG_HASH:=2eb18eb5985963bcf138d1da2f6cad2c5d13744fd2716ad90b12873a56e498a2
else ifeq ($(ARCH_PREBUILT),arm_cortex-a15_neon-vfpv4)
  PKG_HASH:=5af572abd30320b99ab933df3e5208e8df3b6499daed33efbde3b2065a560853
else ifeq ($(ARCH_PREBUILT),arm_cortex-a5_vfpv4)
  PKG_HASH:=5f6020827696f2a1bccc06c20fb3927a63192e516a0da504b6e86708842e044c
else ifeq ($(ARCH_PREBUILT),arm_cortex-a7)
  PKG_HASH:=8171a8ca5b7c181b2c74664bf4ab936aac6237bd28f21a1a01b7bae2f715359c
else ifeq ($(ARCH_PREBUILT),arm_cortex-a7_neon-vfpv4)
  PKG_HASH:=d432aa1c7ea9cc8782d62d7812a733f3ac966f04c022f92487d64ebc2c625fe7
else ifeq ($(ARCH_PREBUILT),arm_cortex-a7_vfpv4)
  PKG_HASH:=9d6453f6693dc1f25483ae7004dc2cf15b8365afe2407dcfec8371957a2f84a6
else ifeq ($(ARCH_PREBUILT),arm_cortex-a8_vfpv3)
  PKG_HASH:=c6c6d7ae66af91b2398e32b0e839e71feade78a4175e8c97c56d5b06dd135506
else ifeq ($(ARCH_PREBUILT),arm_cortex-a9)
  PKG_HASH:=dc4a551462ae9063e6e6ed45d5327e3d4a69d909e40531bde94835ff26f3b2bc
else ifeq ($(ARCH_PREBUILT),arm_cortex-a9_neon)
  PKG_HASH:=55bef8e976edf3d46e4829e763a4fef877d59f3cde0d5b19ffa4ec84f8aa04e1
else ifeq ($(ARCH_PREBUILT),arm_cortex-a9_vfpv3-d16)
  PKG_HASH:=5bc4130d214a0a8251a88678a7aad574b7eb59845aa273788b0b758efb365634
else ifeq ($(ARCH_PREBUILT),arm_mpcore)
  PKG_HASH:=566701a5671fdd5130ee386d04fbc99c87d5a9f6e791d1a66cf98dcf8210da63
else ifeq ($(ARCH_PREBUILT),arm_xscale)
  PKG_HASH:=165892ddc641e0d236923b3cd1c2bc88e6525fb2d241fd3c3bdfcc6121f76784
else ifeq ($(ARCH_PREBUILT),mipsel_24kc)
  PKG_HASH:=a4312cce79040abca50b716a8904183cafc07ea057ac1efc52a0c1ffd2ae6502
else ifeq ($(ARCH_PREBUILT),mipsel_mips32)
  PKG_HASH:=40ad0226eaa34cf8a6fac95389000fc671f0f4d5b0337f2f83b60e63c1cf8728
else ifeq ($(ARCH_PREBUILT),riscv64)
  PKG_HASH:=45893e72697a90f484c6b22fb79ec92fc4cd80acd5425475bca53cd05f99713c
else ifeq ($(ARCH_PREBUILT),x86)
  PKG_HASH:=ae4e441cddf775c99ff1bd5b901c387f778e45a69774d826a797ba8f9abbbad8
else ifeq ($(ARCH_PREBUILT),x86_64)
  PKG_HASH:=25ac92b86474fc62ed0e5008d7009f935115b9ae8a072f1fbafc92790ea283ce
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
