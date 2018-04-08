/* Copyright 2018 Boris Vinogradov <no111u3@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Hardware support for usb_otg_fs
 * @file usb_otg_fs.hh
 * @author Boris Vinogradov
 */

#include <associate_bit.hh>
#include <io_register.hh>
#include <types.hh>

#ifndef USB_OTG_FS_HH
#define USB_OTG_FS_HH

/* USB on the go full speed */
template <lp::addr_t base_address>
struct otg_fs_global_t {
    /* OTG_FS control and status register           (OTG_FS_GOTGCTL) */
    using fs_gotgctl = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Session request success */
    using fs_gotgctl_srqscs = lp::assoc_bit<fs_gotgctl, 0>;
    /* Session request */
    using fs_gotgctl_srq = lp::assoc_bit<fs_gotgctl, 1>;
    /* Host negotiation success */
    using fs_gotgctl_hngscs = lp::assoc_bit<fs_gotgctl, 8>;
    /* HNP request */
    using fs_gotgctl_hnprq = lp::assoc_bit<fs_gotgctl, 9>;
    /* Host set HNP enable */
    using fs_gotgctl_hshnpen = lp::assoc_bit<fs_gotgctl, 10>;
    /* Device HNP enabled */
    using fs_gotgctl_dhnpen = lp::assoc_bit<fs_gotgctl, 11>;
    /* Connector ID status */
    using fs_gotgctl_cidsts = lp::assoc_bit<fs_gotgctl, 16>;
    /* Long/short debounce time */
    using fs_gotgctl_dbct = lp::assoc_bit<fs_gotgctl, 17>;
    /* A-session valid */
    using fs_gotgctl_asvld = lp::assoc_bit<fs_gotgctl, 18>;
    /* B-session valid */
    using fs_gotgctl_bsvld = lp::assoc_bit<fs_gotgctl, 19>;


    /* OTG_FS interrupt register           (OTG_FS_GOTGINT) */
    using fs_gotgint = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Session end detected */
    using fs_gotgint_sedet = lp::assoc_bit<fs_gotgint, 2>;
    /* Session request success status               change */
    using fs_gotgint_srsschg = lp::assoc_bit<fs_gotgint, 8>;
    /* Host negotiation success status               change */
    using fs_gotgint_hnsschg = lp::assoc_bit<fs_gotgint, 9>;
    /* Host negotiation detected */
    using fs_gotgint_hngdet = lp::assoc_bit<fs_gotgint, 17>;
    /* A-device timeout change */
    using fs_gotgint_adtochg = lp::assoc_bit<fs_gotgint, 18>;
    /* Debounce done */
    using fs_gotgint_dbcdne = lp::assoc_bit<fs_gotgint, 19>;


    /* OTG_FS AHB configuration register           (OTG_FS_GAHBCFG) */
    using fs_gahbcfg = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Global interrupt mask */
    using fs_gahbcfg_gint = lp::assoc_bit<fs_gahbcfg, 0>;
    /* TxFIFO empty level */
    using fs_gahbcfg_txfelvl = lp::assoc_bit<fs_gahbcfg, 7>;
    /* Periodic TxFIFO empty               level */
    using fs_gahbcfg_ptxfelvl = lp::assoc_bit<fs_gahbcfg, 8>;


    /* OTG_FS USB configuration register           (OTG_FS_GUSBCFG) */
    using fs_gusbcfg = lp::io_register<lp::u32_t, base_address + 0xc>;
    /* FS timeout calibration */
    using fs_gusbcfg_tocal = lp::assoc_bit<fs_gusbcfg, 0, 3>;
    /* Full Speed serial transceiver               select */
    using fs_gusbcfg_physel = lp::assoc_bit<fs_gusbcfg, 6>;
    /* SRP-capable */
    using fs_gusbcfg_srpcap = lp::assoc_bit<fs_gusbcfg, 8>;
    /* HNP-capable */
    using fs_gusbcfg_hnpcap = lp::assoc_bit<fs_gusbcfg, 9>;
    /* USB turnaround time */
    using fs_gusbcfg_trdt = lp::assoc_bit<fs_gusbcfg, 10, 4>;
    /* Force host mode */
    using fs_gusbcfg_fhmod = lp::assoc_bit<fs_gusbcfg, 29>;
    /* Force device mode */
    using fs_gusbcfg_fdmod = lp::assoc_bit<fs_gusbcfg, 30>;
    /* Corrupt Tx packet */
    using fs_gusbcfg_ctxpkt = lp::assoc_bit<fs_gusbcfg, 31>;


    /* OTG_FS reset register           (OTG_FS_GRSTCTL) */
    using fs_grstctl = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Core soft reset */
    using fs_grstctl_csrst = lp::assoc_bit<fs_grstctl, 0>;
    /* HCLK soft reset */
    using fs_grstctl_hsrst = lp::assoc_bit<fs_grstctl, 1>;
    /* Host frame counter reset */
    using fs_grstctl_fcrst = lp::assoc_bit<fs_grstctl, 2>;
    /* RxFIFO flush */
    using fs_grstctl_rxfflsh = lp::assoc_bit<fs_grstctl, 4>;
    /* TxFIFO flush */
    using fs_grstctl_txfflsh = lp::assoc_bit<fs_grstctl, 5>;
    /* TxFIFO number */
    using fs_grstctl_txfnum = lp::assoc_bit<fs_grstctl, 6, 5>;
    /* AHB master idle */
    using fs_grstctl_ahbidl = lp::assoc_bit<fs_grstctl, 31>;


    /* OTG_FS core interrupt register           (OTG_FS_GINTSTS) */
    using fs_gintsts = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Current mode of operation */
    using fs_gintsts_cmod = lp::assoc_bit<fs_gintsts, 0>;
    /* Mode mismatch interrupt */
    using fs_gintsts_mmis = lp::assoc_bit<fs_gintsts, 1>;
    /* OTG interrupt */
    using fs_gintsts_otgint = lp::assoc_bit<fs_gintsts, 2>;
    /* Start of frame */
    using fs_gintsts_sof = lp::assoc_bit<fs_gintsts, 3>;
    /* RxFIFO non-empty */
    using fs_gintsts_rxflvl = lp::assoc_bit<fs_gintsts, 4>;
    /* Non-periodic TxFIFO empty */
    using fs_gintsts_nptxfe = lp::assoc_bit<fs_gintsts, 5>;
    /* Global IN non-periodic NAK               effective */
    using fs_gintsts_ginakeff = lp::assoc_bit<fs_gintsts, 6>;
    /* Global OUT NAK effective */
    using fs_gintsts_goutnakeff = lp::assoc_bit<fs_gintsts, 7>;
    /* Early suspend */
    using fs_gintsts_esusp = lp::assoc_bit<fs_gintsts, 10>;
    /* USB suspend */
    using fs_gintsts_usbsusp = lp::assoc_bit<fs_gintsts, 11>;
    /* USB reset */
    using fs_gintsts_usbrst = lp::assoc_bit<fs_gintsts, 12>;
    /* Enumeration done */
    using fs_gintsts_enumdne = lp::assoc_bit<fs_gintsts, 13>;
    /* Isochronous OUT packet dropped               interrupt */
    using fs_gintsts_isoodrp = lp::assoc_bit<fs_gintsts, 14>;
    /* End of periodic frame               interrupt */
    using fs_gintsts_eopf = lp::assoc_bit<fs_gintsts, 15>;
    /* IN endpoint interrupt */
    using fs_gintsts_iepint = lp::assoc_bit<fs_gintsts, 18>;
    /* OUT endpoint interrupt */
    using fs_gintsts_oepint = lp::assoc_bit<fs_gintsts, 19>;
    /* Incomplete isochronous IN               transfer */
    using fs_gintsts_iisoixfr = lp::assoc_bit<fs_gintsts, 20>;
    /* Incomplete periodic transfer(Host               mode)/Incomplete isochronous OUT transfer(Device               mode) */
    using fs_gintsts_ipxfr_incompisoout = lp::assoc_bit<fs_gintsts, 21>;
    /* Host port interrupt */
    using fs_gintsts_hprtint = lp::assoc_bit<fs_gintsts, 24>;
    /* Host channels interrupt */
    using fs_gintsts_hcint = lp::assoc_bit<fs_gintsts, 25>;
    /* Periodic TxFIFO empty */
    using fs_gintsts_ptxfe = lp::assoc_bit<fs_gintsts, 26>;
    /* Connector ID status change */
    using fs_gintsts_cidschg = lp::assoc_bit<fs_gintsts, 28>;
    /* Disconnect detected               interrupt */
    using fs_gintsts_discint = lp::assoc_bit<fs_gintsts, 29>;
    /* Session request/new session detected               interrupt */
    using fs_gintsts_srqint = lp::assoc_bit<fs_gintsts, 30>;
    /* Resume/remote wakeup detected               interrupt */
    using fs_gintsts_wkupint = lp::assoc_bit<fs_gintsts, 31>;


    /* OTG_FS interrupt mask register           (OTG_FS_GINTMSK) */
    using fs_gintmsk = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Mode mismatch interrupt               mask */
    using fs_gintmsk_mmism = lp::assoc_bit<fs_gintmsk, 1>;
    /* OTG interrupt mask */
    using fs_gintmsk_otgint = lp::assoc_bit<fs_gintmsk, 2>;
    /* Start of frame mask */
    using fs_gintmsk_sofm = lp::assoc_bit<fs_gintmsk, 3>;
    /* Receive FIFO non-empty               mask */
    using fs_gintmsk_rxflvlm = lp::assoc_bit<fs_gintmsk, 4>;
    /* Non-periodic TxFIFO empty               mask */
    using fs_gintmsk_nptxfem = lp::assoc_bit<fs_gintmsk, 5>;
    /* Global non-periodic IN NAK effective               mask */
    using fs_gintmsk_ginakeffm = lp::assoc_bit<fs_gintmsk, 6>;
    /* Global OUT NAK effective               mask */
    using fs_gintmsk_gonakeffm = lp::assoc_bit<fs_gintmsk, 7>;
    /* Early suspend mask */
    using fs_gintmsk_esuspm = lp::assoc_bit<fs_gintmsk, 10>;
    /* USB suspend mask */
    using fs_gintmsk_usbsuspm = lp::assoc_bit<fs_gintmsk, 11>;
    /* USB reset mask */
    using fs_gintmsk_usbrst = lp::assoc_bit<fs_gintmsk, 12>;
    /* Enumeration done mask */
    using fs_gintmsk_enumdnem = lp::assoc_bit<fs_gintmsk, 13>;
    /* Isochronous OUT packet dropped interrupt               mask */
    using fs_gintmsk_isoodrpm = lp::assoc_bit<fs_gintmsk, 14>;
    /* End of periodic frame interrupt               mask */
    using fs_gintmsk_eopfm = lp::assoc_bit<fs_gintmsk, 15>;
    /* Endpoint mismatch interrupt               mask */
    using fs_gintmsk_epmism = lp::assoc_bit<fs_gintmsk, 17>;
    /* IN endpoints interrupt               mask */
    using fs_gintmsk_iepint = lp::assoc_bit<fs_gintmsk, 18>;
    /* OUT endpoints interrupt               mask */
    using fs_gintmsk_oepint = lp::assoc_bit<fs_gintmsk, 19>;
    /* Incomplete isochronous IN transfer               mask */
    using fs_gintmsk_iisoixfrm = lp::assoc_bit<fs_gintmsk, 20>;
    /* Incomplete periodic transfer mask(Host               mode)/Incomplete isochronous OUT transfer mask(Device               mode) */
    using fs_gintmsk_ipxfrm_iisooxfrm = lp::assoc_bit<fs_gintmsk, 21>;
    /* Host port interrupt mask */
    using fs_gintmsk_prtim = lp::assoc_bit<fs_gintmsk, 24>;
    /* Host channels interrupt               mask */
    using fs_gintmsk_hcim = lp::assoc_bit<fs_gintmsk, 25>;
    /* Periodic TxFIFO empty mask */
    using fs_gintmsk_ptxfem = lp::assoc_bit<fs_gintmsk, 26>;
    /* Connector ID status change               mask */
    using fs_gintmsk_cidschgm = lp::assoc_bit<fs_gintmsk, 28>;
    /* Disconnect detected interrupt               mask */
    using fs_gintmsk_discint = lp::assoc_bit<fs_gintmsk, 29>;
    /* Session request/new session detected               interrupt mask */
    using fs_gintmsk_srqim = lp::assoc_bit<fs_gintmsk, 30>;
    /* Resume/remote wakeup detected interrupt               mask */
    using fs_gintmsk_wuim = lp::assoc_bit<fs_gintmsk, 31>;


    /* OTG_FS Receive status debug read(Device           mode) */
    using fs_grxstsr_device = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Endpoint number */
    using fs_grxstsr_device_epnum = lp::assoc_bit<fs_grxstsr_device, 0, 4>;
    /* Byte count */
    using fs_grxstsr_device_bcnt = lp::assoc_bit<fs_grxstsr_device, 4, 11>;
    /* Data PID */
    using fs_grxstsr_device_dpid = lp::assoc_bit<fs_grxstsr_device, 15, 2>;
    /* Packet status */
    using fs_grxstsr_device_pktsts = lp::assoc_bit<fs_grxstsr_device, 17, 4>;
    /* Frame number */
    using fs_grxstsr_device_frmnum = lp::assoc_bit<fs_grxstsr_device, 21, 4>;


    /* OTG_FS Receive status debug read(Host           mode) */
    using fs_grxstsr_host = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* Endpoint number */
    using fs_grxstsr_host_epnum = lp::assoc_bit<fs_grxstsr_host, 0, 4>;
    /* Byte count */
    using fs_grxstsr_host_bcnt = lp::assoc_bit<fs_grxstsr_host, 4, 11>;
    /* Data PID */
    using fs_grxstsr_host_dpid = lp::assoc_bit<fs_grxstsr_host, 15, 2>;
    /* Packet status */
    using fs_grxstsr_host_pktsts = lp::assoc_bit<fs_grxstsr_host, 17, 4>;
    /* Frame number */
    using fs_grxstsr_host_frmnum = lp::assoc_bit<fs_grxstsr_host, 21, 4>;


    /* OTG_FS Receive FIFO size register           (OTG_FS_GRXFSIZ) */
    using fs_grxfsiz = lp::io_register<lp::u32_t, base_address + 0x24>;
    /* RxFIFO depth */
    using fs_grxfsiz_rxfd = lp::assoc_bit<fs_grxfsiz, 0, 16>;


    /* OTG_FS non-periodic transmit FIFO size           register (Device mode) */
    using fs_gnptxfsiz_device = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Endpoint 0 transmit RAM start               address */
    using fs_gnptxfsiz_device_tx0fsa = lp::assoc_bit<fs_gnptxfsiz_device, 0, 16>;
    /* Endpoint 0 TxFIFO depth */
    using fs_gnptxfsiz_device_tx0fd = lp::assoc_bit<fs_gnptxfsiz_device, 16, 16>;


    /* OTG_FS non-periodic transmit FIFO size           register (Host mode) */
    using fs_gnptxfsiz_host = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Non-periodic transmit RAM start               address */
    using fs_gnptxfsiz_host_nptxfsa = lp::assoc_bit<fs_gnptxfsiz_host, 0, 16>;
    /* Non-periodic TxFIFO depth */
    using fs_gnptxfsiz_host_nptxfd = lp::assoc_bit<fs_gnptxfsiz_host, 16, 16>;


    /* OTG_FS non-periodic transmit FIFO/queue           status register (OTG_FS_GNPTXSTS) */
    using fs_gnptxsts = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Non-periodic TxFIFO space               available */
    using fs_gnptxsts_nptxfsav = lp::assoc_bit<fs_gnptxsts, 0, 16>;
    /* Non-periodic transmit request queue               space available */
    using fs_gnptxsts_nptqxsav = lp::assoc_bit<fs_gnptxsts, 16, 8>;
    /* Top of the non-periodic transmit request               queue */
    using fs_gnptxsts_nptxqtop = lp::assoc_bit<fs_gnptxsts, 24, 7>;


    /* OTG_FS general core configuration register           (OTG_FS_GCCFG) */
    using fs_gccfg = lp::io_register<lp::u32_t, base_address + 0x38>;
    /* Power down */
    using fs_gccfg_pwrdwn = lp::assoc_bit<fs_gccfg, 16>;
    /* Enable the VBUS sensing               device */
    using fs_gccfg_vbusasen = lp::assoc_bit<fs_gccfg, 18>;
    /* Enable the VBUS sensing               device */
    using fs_gccfg_vbusbsen = lp::assoc_bit<fs_gccfg, 19>;
    /* SOF output enable */
    using fs_gccfg_sofouten = lp::assoc_bit<fs_gccfg, 20>;


    /* core ID register */
    using fs_cid = lp::io_register<lp::u32_t, base_address + 0x3c>;
    /* Product ID field */
    using fs_cid_product_id = lp::assoc_bit<fs_cid, 0, 32>;


    /* OTG_FS Host periodic transmit FIFO size           register (OTG_FS_HPTXFSIZ) */
    using fs_hptxfsiz = lp::io_register<lp::u32_t, base_address + 0x100>;
    /* Host periodic TxFIFO start               address */
    using fs_hptxfsiz_ptxsa = lp::assoc_bit<fs_hptxfsiz, 0, 16>;
    /* Host periodic TxFIFO depth */
    using fs_hptxfsiz_ptxfsiz = lp::assoc_bit<fs_hptxfsiz, 16, 16>;


    /* OTG_FS device IN endpoint transmit FIFO size           register (OTG_FS_DIEPTXF2) */
    using fs_dieptxf1 = lp::io_register<lp::u32_t, base_address + 0x104>;
    /* IN endpoint FIFO2 transmit RAM start               address */
    using fs_dieptxf1_ineptxsa = lp::assoc_bit<fs_dieptxf1, 0, 16>;
    /* IN endpoint TxFIFO depth */
    using fs_dieptxf1_ineptxfd = lp::assoc_bit<fs_dieptxf1, 16, 16>;


    /* OTG_FS device IN endpoint transmit FIFO size           register (OTG_FS_DIEPTXF3) */
    using fs_dieptxf2 = lp::io_register<lp::u32_t, base_address + 0x108>;
    /* IN endpoint FIFO3 transmit RAM start               address */
    using fs_dieptxf2_ineptxsa = lp::assoc_bit<fs_dieptxf2, 0, 16>;
    /* IN endpoint TxFIFO depth */
    using fs_dieptxf2_ineptxfd = lp::assoc_bit<fs_dieptxf2, 16, 16>;


    /* OTG_FS device IN endpoint transmit FIFO size           register (OTG_FS_DIEPTXF4) */
    using fs_dieptxf3 = lp::io_register<lp::u32_t, base_address + 0x10c>;
    /* IN endpoint FIFO4 transmit RAM start               address */
    using fs_dieptxf3_ineptxsa = lp::assoc_bit<fs_dieptxf3, 0, 16>;
    /* IN endpoint TxFIFO depth */
    using fs_dieptxf3_ineptxfd = lp::assoc_bit<fs_dieptxf3, 16, 16>;


};

/* USB on the go full speed */
template <lp::addr_t base_address>
struct otg_fs_host_t {
    /* OTG_FS host configuration register           (OTG_FS_HCFG) */
    using fs_hcfg = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* FS/LS PHY clock select */
    using fs_hcfg_fslspcs = lp::assoc_bit<fs_hcfg, 0, 2>;
    /* FS- and LS-only support */
    using fs_hcfg_fslss = lp::assoc_bit<fs_hcfg, 2>;


    /* OTG_FS Host frame interval           register */
    using hfir = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Frame interval */
    using hfir_frivl = lp::assoc_bit<hfir, 0, 16>;


    /* OTG_FS host frame number/frame time           remaining register (OTG_FS_HFNUM) */
    using fs_hfnum = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Frame number */
    using fs_hfnum_frnum = lp::assoc_bit<fs_hfnum, 0, 16>;
    /* Frame time remaining */
    using fs_hfnum_ftrem = lp::assoc_bit<fs_hfnum, 16, 16>;


    /* OTG_FS_Host periodic transmit FIFO/queue           status register (OTG_FS_HPTXSTS) */
    using fs_hptxsts = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Periodic transmit data FIFO space               available */
    using fs_hptxsts_ptxfsavl = lp::assoc_bit<fs_hptxsts, 0, 16>;
    /* Periodic transmit request queue space               available */
    using fs_hptxsts_ptxqsav = lp::assoc_bit<fs_hptxsts, 16, 8>;
    /* Top of the periodic transmit request               queue */
    using fs_hptxsts_ptxqtop = lp::assoc_bit<fs_hptxsts, 24, 8>;


    /* OTG_FS Host all channels interrupt           register */
    using haint = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Channel interrupts */
    using haint_haint = lp::assoc_bit<haint, 0, 16>;


    /* OTG_FS host all channels interrupt mask           register */
    using haintmsk = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* Channel interrupt mask */
    using haintmsk_haintm = lp::assoc_bit<haintmsk, 0, 16>;


    /* OTG_FS host port control and status register           (OTG_FS_HPRT) */
    using fs_hprt = lp::io_register<lp::u32_t, base_address + 0x40>;
    /* Port connect status */
    using fs_hprt_pcsts = lp::assoc_bit<fs_hprt, 0>;
    /* Port connect detected */
    using fs_hprt_pcdet = lp::assoc_bit<fs_hprt, 1>;
    /* Port enable */
    using fs_hprt_pena = lp::assoc_bit<fs_hprt, 2>;
    /* Port enable/disable change */
    using fs_hprt_penchng = lp::assoc_bit<fs_hprt, 3>;
    /* Port overcurrent active */
    using fs_hprt_poca = lp::assoc_bit<fs_hprt, 4>;
    /* Port overcurrent change */
    using fs_hprt_pocchng = lp::assoc_bit<fs_hprt, 5>;
    /* Port resume */
    using fs_hprt_pres = lp::assoc_bit<fs_hprt, 6>;
    /* Port suspend */
    using fs_hprt_psusp = lp::assoc_bit<fs_hprt, 7>;
    /* Port reset */
    using fs_hprt_prst = lp::assoc_bit<fs_hprt, 8>;
    /* Port line status */
    using fs_hprt_plsts = lp::assoc_bit<fs_hprt, 10, 2>;
    /* Port power */
    using fs_hprt_ppwr = lp::assoc_bit<fs_hprt, 12>;
    /* Port test control */
    using fs_hprt_ptctl = lp::assoc_bit<fs_hprt, 13, 4>;
    /* Port speed */
    using fs_hprt_pspd = lp::assoc_bit<fs_hprt, 17, 2>;


    /* OTG_FS host channel-0 characteristics           register (OTG_FS_HCCHAR0) */
    using fs_hcchar0 = lp::io_register<lp::u32_t, base_address + 0x100>;
    /* Maximum packet size */
    using fs_hcchar0_mpsiz = lp::assoc_bit<fs_hcchar0, 0, 11>;
    /* Endpoint number */
    using fs_hcchar0_epnum = lp::assoc_bit<fs_hcchar0, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar0_epdir = lp::assoc_bit<fs_hcchar0, 15>;
    /* Low-speed device */
    using fs_hcchar0_lsdev = lp::assoc_bit<fs_hcchar0, 17>;
    /* Endpoint type */
    using fs_hcchar0_eptyp = lp::assoc_bit<fs_hcchar0, 18, 2>;
    /* Multicount */
    using fs_hcchar0_mcnt = lp::assoc_bit<fs_hcchar0, 20, 2>;
    /* Device address */
    using fs_hcchar0_dad = lp::assoc_bit<fs_hcchar0, 22, 7>;
    /* Odd frame */
    using fs_hcchar0_oddfrm = lp::assoc_bit<fs_hcchar0, 29>;
    /* Channel disable */
    using fs_hcchar0_chdis = lp::assoc_bit<fs_hcchar0, 30>;
    /* Channel enable */
    using fs_hcchar0_chena = lp::assoc_bit<fs_hcchar0, 31>;


    /* OTG_FS host channel-1 characteristics           register (OTG_FS_HCCHAR1) */
    using fs_hcchar1 = lp::io_register<lp::u32_t, base_address + 0x120>;
    /* Maximum packet size */
    using fs_hcchar1_mpsiz = lp::assoc_bit<fs_hcchar1, 0, 11>;
    /* Endpoint number */
    using fs_hcchar1_epnum = lp::assoc_bit<fs_hcchar1, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar1_epdir = lp::assoc_bit<fs_hcchar1, 15>;
    /* Low-speed device */
    using fs_hcchar1_lsdev = lp::assoc_bit<fs_hcchar1, 17>;
    /* Endpoint type */
    using fs_hcchar1_eptyp = lp::assoc_bit<fs_hcchar1, 18, 2>;
    /* Multicount */
    using fs_hcchar1_mcnt = lp::assoc_bit<fs_hcchar1, 20, 2>;
    /* Device address */
    using fs_hcchar1_dad = lp::assoc_bit<fs_hcchar1, 22, 7>;
    /* Odd frame */
    using fs_hcchar1_oddfrm = lp::assoc_bit<fs_hcchar1, 29>;
    /* Channel disable */
    using fs_hcchar1_chdis = lp::assoc_bit<fs_hcchar1, 30>;
    /* Channel enable */
    using fs_hcchar1_chena = lp::assoc_bit<fs_hcchar1, 31>;


    /* OTG_FS host channel-2 characteristics           register (OTG_FS_HCCHAR2) */
    using fs_hcchar2 = lp::io_register<lp::u32_t, base_address + 0x140>;
    /* Maximum packet size */
    using fs_hcchar2_mpsiz = lp::assoc_bit<fs_hcchar2, 0, 11>;
    /* Endpoint number */
    using fs_hcchar2_epnum = lp::assoc_bit<fs_hcchar2, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar2_epdir = lp::assoc_bit<fs_hcchar2, 15>;
    /* Low-speed device */
    using fs_hcchar2_lsdev = lp::assoc_bit<fs_hcchar2, 17>;
    /* Endpoint type */
    using fs_hcchar2_eptyp = lp::assoc_bit<fs_hcchar2, 18, 2>;
    /* Multicount */
    using fs_hcchar2_mcnt = lp::assoc_bit<fs_hcchar2, 20, 2>;
    /* Device address */
    using fs_hcchar2_dad = lp::assoc_bit<fs_hcchar2, 22, 7>;
    /* Odd frame */
    using fs_hcchar2_oddfrm = lp::assoc_bit<fs_hcchar2, 29>;
    /* Channel disable */
    using fs_hcchar2_chdis = lp::assoc_bit<fs_hcchar2, 30>;
    /* Channel enable */
    using fs_hcchar2_chena = lp::assoc_bit<fs_hcchar2, 31>;


    /* OTG_FS host channel-3 characteristics           register (OTG_FS_HCCHAR3) */
    using fs_hcchar3 = lp::io_register<lp::u32_t, base_address + 0x160>;
    /* Maximum packet size */
    using fs_hcchar3_mpsiz = lp::assoc_bit<fs_hcchar3, 0, 11>;
    /* Endpoint number */
    using fs_hcchar3_epnum = lp::assoc_bit<fs_hcchar3, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar3_epdir = lp::assoc_bit<fs_hcchar3, 15>;
    /* Low-speed device */
    using fs_hcchar3_lsdev = lp::assoc_bit<fs_hcchar3, 17>;
    /* Endpoint type */
    using fs_hcchar3_eptyp = lp::assoc_bit<fs_hcchar3, 18, 2>;
    /* Multicount */
    using fs_hcchar3_mcnt = lp::assoc_bit<fs_hcchar3, 20, 2>;
    /* Device address */
    using fs_hcchar3_dad = lp::assoc_bit<fs_hcchar3, 22, 7>;
    /* Odd frame */
    using fs_hcchar3_oddfrm = lp::assoc_bit<fs_hcchar3, 29>;
    /* Channel disable */
    using fs_hcchar3_chdis = lp::assoc_bit<fs_hcchar3, 30>;
    /* Channel enable */
    using fs_hcchar3_chena = lp::assoc_bit<fs_hcchar3, 31>;


    /* OTG_FS host channel-4 characteristics           register (OTG_FS_HCCHAR4) */
    using fs_hcchar4 = lp::io_register<lp::u32_t, base_address + 0x180>;
    /* Maximum packet size */
    using fs_hcchar4_mpsiz = lp::assoc_bit<fs_hcchar4, 0, 11>;
    /* Endpoint number */
    using fs_hcchar4_epnum = lp::assoc_bit<fs_hcchar4, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar4_epdir = lp::assoc_bit<fs_hcchar4, 15>;
    /* Low-speed device */
    using fs_hcchar4_lsdev = lp::assoc_bit<fs_hcchar4, 17>;
    /* Endpoint type */
    using fs_hcchar4_eptyp = lp::assoc_bit<fs_hcchar4, 18, 2>;
    /* Multicount */
    using fs_hcchar4_mcnt = lp::assoc_bit<fs_hcchar4, 20, 2>;
    /* Device address */
    using fs_hcchar4_dad = lp::assoc_bit<fs_hcchar4, 22, 7>;
    /* Odd frame */
    using fs_hcchar4_oddfrm = lp::assoc_bit<fs_hcchar4, 29>;
    /* Channel disable */
    using fs_hcchar4_chdis = lp::assoc_bit<fs_hcchar4, 30>;
    /* Channel enable */
    using fs_hcchar4_chena = lp::assoc_bit<fs_hcchar4, 31>;


    /* OTG_FS host channel-5 characteristics           register (OTG_FS_HCCHAR5) */
    using fs_hcchar5 = lp::io_register<lp::u32_t, base_address + 0x1a0>;
    /* Maximum packet size */
    using fs_hcchar5_mpsiz = lp::assoc_bit<fs_hcchar5, 0, 11>;
    /* Endpoint number */
    using fs_hcchar5_epnum = lp::assoc_bit<fs_hcchar5, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar5_epdir = lp::assoc_bit<fs_hcchar5, 15>;
    /* Low-speed device */
    using fs_hcchar5_lsdev = lp::assoc_bit<fs_hcchar5, 17>;
    /* Endpoint type */
    using fs_hcchar5_eptyp = lp::assoc_bit<fs_hcchar5, 18, 2>;
    /* Multicount */
    using fs_hcchar5_mcnt = lp::assoc_bit<fs_hcchar5, 20, 2>;
    /* Device address */
    using fs_hcchar5_dad = lp::assoc_bit<fs_hcchar5, 22, 7>;
    /* Odd frame */
    using fs_hcchar5_oddfrm = lp::assoc_bit<fs_hcchar5, 29>;
    /* Channel disable */
    using fs_hcchar5_chdis = lp::assoc_bit<fs_hcchar5, 30>;
    /* Channel enable */
    using fs_hcchar5_chena = lp::assoc_bit<fs_hcchar5, 31>;


    /* OTG_FS host channel-6 characteristics           register (OTG_FS_HCCHAR6) */
    using fs_hcchar6 = lp::io_register<lp::u32_t, base_address + 0x1c0>;
    /* Maximum packet size */
    using fs_hcchar6_mpsiz = lp::assoc_bit<fs_hcchar6, 0, 11>;
    /* Endpoint number */
    using fs_hcchar6_epnum = lp::assoc_bit<fs_hcchar6, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar6_epdir = lp::assoc_bit<fs_hcchar6, 15>;
    /* Low-speed device */
    using fs_hcchar6_lsdev = lp::assoc_bit<fs_hcchar6, 17>;
    /* Endpoint type */
    using fs_hcchar6_eptyp = lp::assoc_bit<fs_hcchar6, 18, 2>;
    /* Multicount */
    using fs_hcchar6_mcnt = lp::assoc_bit<fs_hcchar6, 20, 2>;
    /* Device address */
    using fs_hcchar6_dad = lp::assoc_bit<fs_hcchar6, 22, 7>;
    /* Odd frame */
    using fs_hcchar6_oddfrm = lp::assoc_bit<fs_hcchar6, 29>;
    /* Channel disable */
    using fs_hcchar6_chdis = lp::assoc_bit<fs_hcchar6, 30>;
    /* Channel enable */
    using fs_hcchar6_chena = lp::assoc_bit<fs_hcchar6, 31>;


    /* OTG_FS host channel-7 characteristics           register (OTG_FS_HCCHAR7) */
    using fs_hcchar7 = lp::io_register<lp::u32_t, base_address + 0x1e0>;
    /* Maximum packet size */
    using fs_hcchar7_mpsiz = lp::assoc_bit<fs_hcchar7, 0, 11>;
    /* Endpoint number */
    using fs_hcchar7_epnum = lp::assoc_bit<fs_hcchar7, 11, 4>;
    /* Endpoint direction */
    using fs_hcchar7_epdir = lp::assoc_bit<fs_hcchar7, 15>;
    /* Low-speed device */
    using fs_hcchar7_lsdev = lp::assoc_bit<fs_hcchar7, 17>;
    /* Endpoint type */
    using fs_hcchar7_eptyp = lp::assoc_bit<fs_hcchar7, 18, 2>;
    /* Multicount */
    using fs_hcchar7_mcnt = lp::assoc_bit<fs_hcchar7, 20, 2>;
    /* Device address */
    using fs_hcchar7_dad = lp::assoc_bit<fs_hcchar7, 22, 7>;
    /* Odd frame */
    using fs_hcchar7_oddfrm = lp::assoc_bit<fs_hcchar7, 29>;
    /* Channel disable */
    using fs_hcchar7_chdis = lp::assoc_bit<fs_hcchar7, 30>;
    /* Channel enable */
    using fs_hcchar7_chena = lp::assoc_bit<fs_hcchar7, 31>;


    /* OTG_FS host channel-0 interrupt register           (OTG_FS_HCINT0) */
    using fs_hcint0 = lp::io_register<lp::u32_t, base_address + 0x108>;
    /* Transfer completed */
    using fs_hcint0_xfrc = lp::assoc_bit<fs_hcint0, 0>;
    /* Channel halted */
    using fs_hcint0_chh = lp::assoc_bit<fs_hcint0, 1>;
    /* STALL response received               interrupt */
    using fs_hcint0_stall = lp::assoc_bit<fs_hcint0, 3>;
    /* NAK response received               interrupt */
    using fs_hcint0_nak = lp::assoc_bit<fs_hcint0, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint0_ack = lp::assoc_bit<fs_hcint0, 5>;
    /* Transaction error */
    using fs_hcint0_txerr = lp::assoc_bit<fs_hcint0, 7>;
    /* Babble error */
    using fs_hcint0_bberr = lp::assoc_bit<fs_hcint0, 8>;
    /* Frame overrun */
    using fs_hcint0_frmor = lp::assoc_bit<fs_hcint0, 9>;
    /* Data toggle error */
    using fs_hcint0_dterr = lp::assoc_bit<fs_hcint0, 10>;


    /* OTG_FS host channel-1 interrupt register           (OTG_FS_HCINT1) */
    using fs_hcint1 = lp::io_register<lp::u32_t, base_address + 0x128>;
    /* Transfer completed */
    using fs_hcint1_xfrc = lp::assoc_bit<fs_hcint1, 0>;
    /* Channel halted */
    using fs_hcint1_chh = lp::assoc_bit<fs_hcint1, 1>;
    /* STALL response received               interrupt */
    using fs_hcint1_stall = lp::assoc_bit<fs_hcint1, 3>;
    /* NAK response received               interrupt */
    using fs_hcint1_nak = lp::assoc_bit<fs_hcint1, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint1_ack = lp::assoc_bit<fs_hcint1, 5>;
    /* Transaction error */
    using fs_hcint1_txerr = lp::assoc_bit<fs_hcint1, 7>;
    /* Babble error */
    using fs_hcint1_bberr = lp::assoc_bit<fs_hcint1, 8>;
    /* Frame overrun */
    using fs_hcint1_frmor = lp::assoc_bit<fs_hcint1, 9>;
    /* Data toggle error */
    using fs_hcint1_dterr = lp::assoc_bit<fs_hcint1, 10>;


    /* OTG_FS host channel-2 interrupt register           (OTG_FS_HCINT2) */
    using fs_hcint2 = lp::io_register<lp::u32_t, base_address + 0x148>;
    /* Transfer completed */
    using fs_hcint2_xfrc = lp::assoc_bit<fs_hcint2, 0>;
    /* Channel halted */
    using fs_hcint2_chh = lp::assoc_bit<fs_hcint2, 1>;
    /* STALL response received               interrupt */
    using fs_hcint2_stall = lp::assoc_bit<fs_hcint2, 3>;
    /* NAK response received               interrupt */
    using fs_hcint2_nak = lp::assoc_bit<fs_hcint2, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint2_ack = lp::assoc_bit<fs_hcint2, 5>;
    /* Transaction error */
    using fs_hcint2_txerr = lp::assoc_bit<fs_hcint2, 7>;
    /* Babble error */
    using fs_hcint2_bberr = lp::assoc_bit<fs_hcint2, 8>;
    /* Frame overrun */
    using fs_hcint2_frmor = lp::assoc_bit<fs_hcint2, 9>;
    /* Data toggle error */
    using fs_hcint2_dterr = lp::assoc_bit<fs_hcint2, 10>;


    /* OTG_FS host channel-3 interrupt register           (OTG_FS_HCINT3) */
    using fs_hcint3 = lp::io_register<lp::u32_t, base_address + 0x168>;
    /* Transfer completed */
    using fs_hcint3_xfrc = lp::assoc_bit<fs_hcint3, 0>;
    /* Channel halted */
    using fs_hcint3_chh = lp::assoc_bit<fs_hcint3, 1>;
    /* STALL response received               interrupt */
    using fs_hcint3_stall = lp::assoc_bit<fs_hcint3, 3>;
    /* NAK response received               interrupt */
    using fs_hcint3_nak = lp::assoc_bit<fs_hcint3, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint3_ack = lp::assoc_bit<fs_hcint3, 5>;
    /* Transaction error */
    using fs_hcint3_txerr = lp::assoc_bit<fs_hcint3, 7>;
    /* Babble error */
    using fs_hcint3_bberr = lp::assoc_bit<fs_hcint3, 8>;
    /* Frame overrun */
    using fs_hcint3_frmor = lp::assoc_bit<fs_hcint3, 9>;
    /* Data toggle error */
    using fs_hcint3_dterr = lp::assoc_bit<fs_hcint3, 10>;


    /* OTG_FS host channel-4 interrupt register           (OTG_FS_HCINT4) */
    using fs_hcint4 = lp::io_register<lp::u32_t, base_address + 0x188>;
    /* Transfer completed */
    using fs_hcint4_xfrc = lp::assoc_bit<fs_hcint4, 0>;
    /* Channel halted */
    using fs_hcint4_chh = lp::assoc_bit<fs_hcint4, 1>;
    /* STALL response received               interrupt */
    using fs_hcint4_stall = lp::assoc_bit<fs_hcint4, 3>;
    /* NAK response received               interrupt */
    using fs_hcint4_nak = lp::assoc_bit<fs_hcint4, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint4_ack = lp::assoc_bit<fs_hcint4, 5>;
    /* Transaction error */
    using fs_hcint4_txerr = lp::assoc_bit<fs_hcint4, 7>;
    /* Babble error */
    using fs_hcint4_bberr = lp::assoc_bit<fs_hcint4, 8>;
    /* Frame overrun */
    using fs_hcint4_frmor = lp::assoc_bit<fs_hcint4, 9>;
    /* Data toggle error */
    using fs_hcint4_dterr = lp::assoc_bit<fs_hcint4, 10>;


    /* OTG_FS host channel-5 interrupt register           (OTG_FS_HCINT5) */
    using fs_hcint5 = lp::io_register<lp::u32_t, base_address + 0x1a8>;
    /* Transfer completed */
    using fs_hcint5_xfrc = lp::assoc_bit<fs_hcint5, 0>;
    /* Channel halted */
    using fs_hcint5_chh = lp::assoc_bit<fs_hcint5, 1>;
    /* STALL response received               interrupt */
    using fs_hcint5_stall = lp::assoc_bit<fs_hcint5, 3>;
    /* NAK response received               interrupt */
    using fs_hcint5_nak = lp::assoc_bit<fs_hcint5, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint5_ack = lp::assoc_bit<fs_hcint5, 5>;
    /* Transaction error */
    using fs_hcint5_txerr = lp::assoc_bit<fs_hcint5, 7>;
    /* Babble error */
    using fs_hcint5_bberr = lp::assoc_bit<fs_hcint5, 8>;
    /* Frame overrun */
    using fs_hcint5_frmor = lp::assoc_bit<fs_hcint5, 9>;
    /* Data toggle error */
    using fs_hcint5_dterr = lp::assoc_bit<fs_hcint5, 10>;


    /* OTG_FS host channel-6 interrupt register           (OTG_FS_HCINT6) */
    using fs_hcint6 = lp::io_register<lp::u32_t, base_address + 0x1c8>;
    /* Transfer completed */
    using fs_hcint6_xfrc = lp::assoc_bit<fs_hcint6, 0>;
    /* Channel halted */
    using fs_hcint6_chh = lp::assoc_bit<fs_hcint6, 1>;
    /* STALL response received               interrupt */
    using fs_hcint6_stall = lp::assoc_bit<fs_hcint6, 3>;
    /* NAK response received               interrupt */
    using fs_hcint6_nak = lp::assoc_bit<fs_hcint6, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint6_ack = lp::assoc_bit<fs_hcint6, 5>;
    /* Transaction error */
    using fs_hcint6_txerr = lp::assoc_bit<fs_hcint6, 7>;
    /* Babble error */
    using fs_hcint6_bberr = lp::assoc_bit<fs_hcint6, 8>;
    /* Frame overrun */
    using fs_hcint6_frmor = lp::assoc_bit<fs_hcint6, 9>;
    /* Data toggle error */
    using fs_hcint6_dterr = lp::assoc_bit<fs_hcint6, 10>;


    /* OTG_FS host channel-7 interrupt register           (OTG_FS_HCINT7) */
    using fs_hcint7 = lp::io_register<lp::u32_t, base_address + 0x1e8>;
    /* Transfer completed */
    using fs_hcint7_xfrc = lp::assoc_bit<fs_hcint7, 0>;
    /* Channel halted */
    using fs_hcint7_chh = lp::assoc_bit<fs_hcint7, 1>;
    /* STALL response received               interrupt */
    using fs_hcint7_stall = lp::assoc_bit<fs_hcint7, 3>;
    /* NAK response received               interrupt */
    using fs_hcint7_nak = lp::assoc_bit<fs_hcint7, 4>;
    /* ACK response received/transmitted               interrupt */
    using fs_hcint7_ack = lp::assoc_bit<fs_hcint7, 5>;
    /* Transaction error */
    using fs_hcint7_txerr = lp::assoc_bit<fs_hcint7, 7>;
    /* Babble error */
    using fs_hcint7_bberr = lp::assoc_bit<fs_hcint7, 8>;
    /* Frame overrun */
    using fs_hcint7_frmor = lp::assoc_bit<fs_hcint7, 9>;
    /* Data toggle error */
    using fs_hcint7_dterr = lp::assoc_bit<fs_hcint7, 10>;


    /* OTG_FS host channel-0 mask register           (OTG_FS_HCINTMSK0) */
    using fs_hcintmsk0 = lp::io_register<lp::u32_t, base_address + 0x10c>;
    /* Transfer completed mask */
    using fs_hcintmsk0_xfrcm = lp::assoc_bit<fs_hcintmsk0, 0>;
    /* Channel halted mask */
    using fs_hcintmsk0_chhm = lp::assoc_bit<fs_hcintmsk0, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk0_stallm = lp::assoc_bit<fs_hcintmsk0, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk0_nakm = lp::assoc_bit<fs_hcintmsk0, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk0_ackm = lp::assoc_bit<fs_hcintmsk0, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk0_nyet = lp::assoc_bit<fs_hcintmsk0, 6>;
    /* Transaction error mask */
    using fs_hcintmsk0_txerrm = lp::assoc_bit<fs_hcintmsk0, 7>;
    /* Babble error mask */
    using fs_hcintmsk0_bberrm = lp::assoc_bit<fs_hcintmsk0, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk0_frmorm = lp::assoc_bit<fs_hcintmsk0, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk0_dterrm = lp::assoc_bit<fs_hcintmsk0, 10>;


    /* OTG_FS host channel-1 mask register           (OTG_FS_HCINTMSK1) */
    using fs_hcintmsk1 = lp::io_register<lp::u32_t, base_address + 0x12c>;
    /* Transfer completed mask */
    using fs_hcintmsk1_xfrcm = lp::assoc_bit<fs_hcintmsk1, 0>;
    /* Channel halted mask */
    using fs_hcintmsk1_chhm = lp::assoc_bit<fs_hcintmsk1, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk1_stallm = lp::assoc_bit<fs_hcintmsk1, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk1_nakm = lp::assoc_bit<fs_hcintmsk1, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk1_ackm = lp::assoc_bit<fs_hcintmsk1, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk1_nyet = lp::assoc_bit<fs_hcintmsk1, 6>;
    /* Transaction error mask */
    using fs_hcintmsk1_txerrm = lp::assoc_bit<fs_hcintmsk1, 7>;
    /* Babble error mask */
    using fs_hcintmsk1_bberrm = lp::assoc_bit<fs_hcintmsk1, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk1_frmorm = lp::assoc_bit<fs_hcintmsk1, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk1_dterrm = lp::assoc_bit<fs_hcintmsk1, 10>;


    /* OTG_FS host channel-2 mask register           (OTG_FS_HCINTMSK2) */
    using fs_hcintmsk2 = lp::io_register<lp::u32_t, base_address + 0x14c>;
    /* Transfer completed mask */
    using fs_hcintmsk2_xfrcm = lp::assoc_bit<fs_hcintmsk2, 0>;
    /* Channel halted mask */
    using fs_hcintmsk2_chhm = lp::assoc_bit<fs_hcintmsk2, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk2_stallm = lp::assoc_bit<fs_hcintmsk2, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk2_nakm = lp::assoc_bit<fs_hcintmsk2, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk2_ackm = lp::assoc_bit<fs_hcintmsk2, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk2_nyet = lp::assoc_bit<fs_hcintmsk2, 6>;
    /* Transaction error mask */
    using fs_hcintmsk2_txerrm = lp::assoc_bit<fs_hcintmsk2, 7>;
    /* Babble error mask */
    using fs_hcintmsk2_bberrm = lp::assoc_bit<fs_hcintmsk2, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk2_frmorm = lp::assoc_bit<fs_hcintmsk2, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk2_dterrm = lp::assoc_bit<fs_hcintmsk2, 10>;


    /* OTG_FS host channel-3 mask register           (OTG_FS_HCINTMSK3) */
    using fs_hcintmsk3 = lp::io_register<lp::u32_t, base_address + 0x16c>;
    /* Transfer completed mask */
    using fs_hcintmsk3_xfrcm = lp::assoc_bit<fs_hcintmsk3, 0>;
    /* Channel halted mask */
    using fs_hcintmsk3_chhm = lp::assoc_bit<fs_hcintmsk3, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk3_stallm = lp::assoc_bit<fs_hcintmsk3, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk3_nakm = lp::assoc_bit<fs_hcintmsk3, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk3_ackm = lp::assoc_bit<fs_hcintmsk3, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk3_nyet = lp::assoc_bit<fs_hcintmsk3, 6>;
    /* Transaction error mask */
    using fs_hcintmsk3_txerrm = lp::assoc_bit<fs_hcintmsk3, 7>;
    /* Babble error mask */
    using fs_hcintmsk3_bberrm = lp::assoc_bit<fs_hcintmsk3, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk3_frmorm = lp::assoc_bit<fs_hcintmsk3, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk3_dterrm = lp::assoc_bit<fs_hcintmsk3, 10>;


    /* OTG_FS host channel-4 mask register           (OTG_FS_HCINTMSK4) */
    using fs_hcintmsk4 = lp::io_register<lp::u32_t, base_address + 0x18c>;
    /* Transfer completed mask */
    using fs_hcintmsk4_xfrcm = lp::assoc_bit<fs_hcintmsk4, 0>;
    /* Channel halted mask */
    using fs_hcintmsk4_chhm = lp::assoc_bit<fs_hcintmsk4, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk4_stallm = lp::assoc_bit<fs_hcintmsk4, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk4_nakm = lp::assoc_bit<fs_hcintmsk4, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk4_ackm = lp::assoc_bit<fs_hcintmsk4, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk4_nyet = lp::assoc_bit<fs_hcintmsk4, 6>;
    /* Transaction error mask */
    using fs_hcintmsk4_txerrm = lp::assoc_bit<fs_hcintmsk4, 7>;
    /* Babble error mask */
    using fs_hcintmsk4_bberrm = lp::assoc_bit<fs_hcintmsk4, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk4_frmorm = lp::assoc_bit<fs_hcintmsk4, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk4_dterrm = lp::assoc_bit<fs_hcintmsk4, 10>;


    /* OTG_FS host channel-5 mask register           (OTG_FS_HCINTMSK5) */
    using fs_hcintmsk5 = lp::io_register<lp::u32_t, base_address + 0x1ac>;
    /* Transfer completed mask */
    using fs_hcintmsk5_xfrcm = lp::assoc_bit<fs_hcintmsk5, 0>;
    /* Channel halted mask */
    using fs_hcintmsk5_chhm = lp::assoc_bit<fs_hcintmsk5, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk5_stallm = lp::assoc_bit<fs_hcintmsk5, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk5_nakm = lp::assoc_bit<fs_hcintmsk5, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk5_ackm = lp::assoc_bit<fs_hcintmsk5, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk5_nyet = lp::assoc_bit<fs_hcintmsk5, 6>;
    /* Transaction error mask */
    using fs_hcintmsk5_txerrm = lp::assoc_bit<fs_hcintmsk5, 7>;
    /* Babble error mask */
    using fs_hcintmsk5_bberrm = lp::assoc_bit<fs_hcintmsk5, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk5_frmorm = lp::assoc_bit<fs_hcintmsk5, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk5_dterrm = lp::assoc_bit<fs_hcintmsk5, 10>;


    /* OTG_FS host channel-6 mask register           (OTG_FS_HCINTMSK6) */
    using fs_hcintmsk6 = lp::io_register<lp::u32_t, base_address + 0x1cc>;
    /* Transfer completed mask */
    using fs_hcintmsk6_xfrcm = lp::assoc_bit<fs_hcintmsk6, 0>;
    /* Channel halted mask */
    using fs_hcintmsk6_chhm = lp::assoc_bit<fs_hcintmsk6, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk6_stallm = lp::assoc_bit<fs_hcintmsk6, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk6_nakm = lp::assoc_bit<fs_hcintmsk6, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk6_ackm = lp::assoc_bit<fs_hcintmsk6, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk6_nyet = lp::assoc_bit<fs_hcintmsk6, 6>;
    /* Transaction error mask */
    using fs_hcintmsk6_txerrm = lp::assoc_bit<fs_hcintmsk6, 7>;
    /* Babble error mask */
    using fs_hcintmsk6_bberrm = lp::assoc_bit<fs_hcintmsk6, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk6_frmorm = lp::assoc_bit<fs_hcintmsk6, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk6_dterrm = lp::assoc_bit<fs_hcintmsk6, 10>;


    /* OTG_FS host channel-7 mask register           (OTG_FS_HCINTMSK7) */
    using fs_hcintmsk7 = lp::io_register<lp::u32_t, base_address + 0x1ec>;
    /* Transfer completed mask */
    using fs_hcintmsk7_xfrcm = lp::assoc_bit<fs_hcintmsk7, 0>;
    /* Channel halted mask */
    using fs_hcintmsk7_chhm = lp::assoc_bit<fs_hcintmsk7, 1>;
    /* STALL response received interrupt               mask */
    using fs_hcintmsk7_stallm = lp::assoc_bit<fs_hcintmsk7, 3>;
    /* NAK response received interrupt               mask */
    using fs_hcintmsk7_nakm = lp::assoc_bit<fs_hcintmsk7, 4>;
    /* ACK response received/transmitted               interrupt mask */
    using fs_hcintmsk7_ackm = lp::assoc_bit<fs_hcintmsk7, 5>;
    /* response received interrupt               mask */
    using fs_hcintmsk7_nyet = lp::assoc_bit<fs_hcintmsk7, 6>;
    /* Transaction error mask */
    using fs_hcintmsk7_txerrm = lp::assoc_bit<fs_hcintmsk7, 7>;
    /* Babble error mask */
    using fs_hcintmsk7_bberrm = lp::assoc_bit<fs_hcintmsk7, 8>;
    /* Frame overrun mask */
    using fs_hcintmsk7_frmorm = lp::assoc_bit<fs_hcintmsk7, 9>;
    /* Data toggle error mask */
    using fs_hcintmsk7_dterrm = lp::assoc_bit<fs_hcintmsk7, 10>;


    /* OTG_FS host channel-0 transfer size           register */
    using fs_hctsiz0 = lp::io_register<lp::u32_t, base_address + 0x110>;
    /* Transfer size */
    using fs_hctsiz0_xfrsiz = lp::assoc_bit<fs_hctsiz0, 0, 19>;
    /* Packet count */
    using fs_hctsiz0_pktcnt = lp::assoc_bit<fs_hctsiz0, 19, 10>;
    /* Data PID */
    using fs_hctsiz0_dpid = lp::assoc_bit<fs_hctsiz0, 29, 2>;


    /* OTG_FS host channel-1 transfer size           register */
    using fs_hctsiz1 = lp::io_register<lp::u32_t, base_address + 0x130>;
    /* Transfer size */
    using fs_hctsiz1_xfrsiz = lp::assoc_bit<fs_hctsiz1, 0, 19>;
    /* Packet count */
    using fs_hctsiz1_pktcnt = lp::assoc_bit<fs_hctsiz1, 19, 10>;
    /* Data PID */
    using fs_hctsiz1_dpid = lp::assoc_bit<fs_hctsiz1, 29, 2>;


    /* OTG_FS host channel-2 transfer size           register */
    using fs_hctsiz2 = lp::io_register<lp::u32_t, base_address + 0x150>;
    /* Transfer size */
    using fs_hctsiz2_xfrsiz = lp::assoc_bit<fs_hctsiz2, 0, 19>;
    /* Packet count */
    using fs_hctsiz2_pktcnt = lp::assoc_bit<fs_hctsiz2, 19, 10>;
    /* Data PID */
    using fs_hctsiz2_dpid = lp::assoc_bit<fs_hctsiz2, 29, 2>;


    /* OTG_FS host channel-3 transfer size           register */
    using fs_hctsiz3 = lp::io_register<lp::u32_t, base_address + 0x170>;
    /* Transfer size */
    using fs_hctsiz3_xfrsiz = lp::assoc_bit<fs_hctsiz3, 0, 19>;
    /* Packet count */
    using fs_hctsiz3_pktcnt = lp::assoc_bit<fs_hctsiz3, 19, 10>;
    /* Data PID */
    using fs_hctsiz3_dpid = lp::assoc_bit<fs_hctsiz3, 29, 2>;


    /* OTG_FS host channel-x transfer size           register */
    using fs_hctsiz4 = lp::io_register<lp::u32_t, base_address + 0x190>;
    /* Transfer size */
    using fs_hctsiz4_xfrsiz = lp::assoc_bit<fs_hctsiz4, 0, 19>;
    /* Packet count */
    using fs_hctsiz4_pktcnt = lp::assoc_bit<fs_hctsiz4, 19, 10>;
    /* Data PID */
    using fs_hctsiz4_dpid = lp::assoc_bit<fs_hctsiz4, 29, 2>;


    /* OTG_FS host channel-5 transfer size           register */
    using fs_hctsiz5 = lp::io_register<lp::u32_t, base_address + 0x1b0>;
    /* Transfer size */
    using fs_hctsiz5_xfrsiz = lp::assoc_bit<fs_hctsiz5, 0, 19>;
    /* Packet count */
    using fs_hctsiz5_pktcnt = lp::assoc_bit<fs_hctsiz5, 19, 10>;
    /* Data PID */
    using fs_hctsiz5_dpid = lp::assoc_bit<fs_hctsiz5, 29, 2>;


    /* OTG_FS host channel-6 transfer size           register */
    using fs_hctsiz6 = lp::io_register<lp::u32_t, base_address + 0x1d0>;
    /* Transfer size */
    using fs_hctsiz6_xfrsiz = lp::assoc_bit<fs_hctsiz6, 0, 19>;
    /* Packet count */
    using fs_hctsiz6_pktcnt = lp::assoc_bit<fs_hctsiz6, 19, 10>;
    /* Data PID */
    using fs_hctsiz6_dpid = lp::assoc_bit<fs_hctsiz6, 29, 2>;


    /* OTG_FS host channel-7 transfer size           register */
    using fs_hctsiz7 = lp::io_register<lp::u32_t, base_address + 0x1f0>;
    /* Transfer size */
    using fs_hctsiz7_xfrsiz = lp::assoc_bit<fs_hctsiz7, 0, 19>;
    /* Packet count */
    using fs_hctsiz7_pktcnt = lp::assoc_bit<fs_hctsiz7, 19, 10>;
    /* Data PID */
    using fs_hctsiz7_dpid = lp::assoc_bit<fs_hctsiz7, 29, 2>;


};

/* USB on the go full speed */
template <lp::addr_t base_address>
struct otg_fs_device_t {
    /* OTG_FS device configuration register           (OTG_FS_DCFG) */
    using fs_dcfg = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Device speed */
    using fs_dcfg_dspd = lp::assoc_bit<fs_dcfg, 0, 2>;
    /* Non-zero-length status OUT               handshake */
    using fs_dcfg_nzlsohsk = lp::assoc_bit<fs_dcfg, 2>;
    /* Device address */
    using fs_dcfg_dad = lp::assoc_bit<fs_dcfg, 4, 7>;
    /* Periodic frame interval */
    using fs_dcfg_pfivl = lp::assoc_bit<fs_dcfg, 11, 2>;


    /* OTG_FS device control register           (OTG_FS_DCTL) */
    using fs_dctl = lp::io_register<lp::u32_t, base_address + 0x4>;
    /* Remote wakeup signaling */
    using fs_dctl_rwusig = lp::assoc_bit<fs_dctl, 0>;
    /* Soft disconnect */
    using fs_dctl_sdis = lp::assoc_bit<fs_dctl, 1>;
    /* Global IN NAK status */
    using fs_dctl_ginsts = lp::assoc_bit<fs_dctl, 2>;
    /* Global OUT NAK status */
    using fs_dctl_gonsts = lp::assoc_bit<fs_dctl, 3>;
    /* Test control */
    using fs_dctl_tctl = lp::assoc_bit<fs_dctl, 4, 3>;
    /* Set global IN NAK */
    using fs_dctl_sginak = lp::assoc_bit<fs_dctl, 7>;
    /* Clear global IN NAK */
    using fs_dctl_cginak = lp::assoc_bit<fs_dctl, 8>;
    /* Set global OUT NAK */
    using fs_dctl_sgonak = lp::assoc_bit<fs_dctl, 9>;
    /* Clear global OUT NAK */
    using fs_dctl_cgonak = lp::assoc_bit<fs_dctl, 10>;
    /* Power-on programming done */
    using fs_dctl_poprgdne = lp::assoc_bit<fs_dctl, 11>;


    /* OTG_FS device status register           (OTG_FS_DSTS) */
    using fs_dsts = lp::io_register<lp::u32_t, base_address + 0x8>;
    /* Suspend status */
    using fs_dsts_suspsts = lp::assoc_bit<fs_dsts, 0>;
    /* Enumerated speed */
    using fs_dsts_enumspd = lp::assoc_bit<fs_dsts, 1, 2>;
    /* Erratic error */
    using fs_dsts_eerr = lp::assoc_bit<fs_dsts, 3>;
    /* Frame number of the received               SOF */
    using fs_dsts_fnsof = lp::assoc_bit<fs_dsts, 8, 14>;


    /* OTG_FS device IN endpoint common interrupt           mask register (OTG_FS_DIEPMSK) */
    using fs_diepmsk = lp::io_register<lp::u32_t, base_address + 0x10>;
    /* Transfer completed interrupt               mask */
    using fs_diepmsk_xfrcm = lp::assoc_bit<fs_diepmsk, 0>;
    /* Endpoint disabled interrupt               mask */
    using fs_diepmsk_epdm = lp::assoc_bit<fs_diepmsk, 1>;
    /* Timeout condition mask (Non-isochronous               endpoints) */
    using fs_diepmsk_tom = lp::assoc_bit<fs_diepmsk, 3>;
    /* IN token received when TxFIFO empty               mask */
    using fs_diepmsk_ittxfemsk = lp::assoc_bit<fs_diepmsk, 4>;
    /* IN token received with EP mismatch               mask */
    using fs_diepmsk_inepnmm = lp::assoc_bit<fs_diepmsk, 5>;
    /* IN endpoint NAK effective               mask */
    using fs_diepmsk_inepnem = lp::assoc_bit<fs_diepmsk, 6>;


    /* OTG_FS device OUT endpoint common interrupt           mask register (OTG_FS_DOEPMSK) */
    using fs_doepmsk = lp::io_register<lp::u32_t, base_address + 0x14>;
    /* Transfer completed interrupt               mask */
    using fs_doepmsk_xfrcm = lp::assoc_bit<fs_doepmsk, 0>;
    /* Endpoint disabled interrupt               mask */
    using fs_doepmsk_epdm = lp::assoc_bit<fs_doepmsk, 1>;
    /* SETUP phase done mask */
    using fs_doepmsk_stupm = lp::assoc_bit<fs_doepmsk, 3>;
    /* OUT token received when endpoint               disabled mask */
    using fs_doepmsk_otepdm = lp::assoc_bit<fs_doepmsk, 4>;


    /* OTG_FS device all endpoints interrupt           register (OTG_FS_DAINT) */
    using fs_daint = lp::io_register<lp::u32_t, base_address + 0x18>;
    /* IN endpoint interrupt bits */
    using fs_daint_iepint = lp::assoc_bit<fs_daint, 0, 16>;
    /* OUT endpoint interrupt               bits */
    using fs_daint_oepint = lp::assoc_bit<fs_daint, 16, 16>;


    /* OTG_FS all endpoints interrupt mask register           (OTG_FS_DAINTMSK) */
    using fs_daintmsk = lp::io_register<lp::u32_t, base_address + 0x1c>;
    /* IN EP interrupt mask bits */
    using fs_daintmsk_iepm = lp::assoc_bit<fs_daintmsk, 0, 16>;
    /* OUT endpoint interrupt               bits */
    using fs_daintmsk_oepint = lp::assoc_bit<fs_daintmsk, 16, 16>;


    /* OTG_FS device VBUS discharge time           register */
    using dvbusdis = lp::io_register<lp::u32_t, base_address + 0x28>;
    /* Device VBUS discharge time */
    using dvbusdis_vbusdt = lp::assoc_bit<dvbusdis, 0, 16>;


    /* OTG_FS device VBUS pulsing time           register */
    using dvbuspulse = lp::io_register<lp::u32_t, base_address + 0x2c>;
    /* Device VBUS pulsing time */
    using dvbuspulse_dvbusp = lp::assoc_bit<dvbuspulse, 0, 12>;


    /* OTG_FS device IN endpoint FIFO empty           interrupt mask register */
    using diepempmsk = lp::io_register<lp::u32_t, base_address + 0x34>;
    /* IN EP Tx FIFO empty interrupt mask               bits */
    using diepempmsk_ineptxfem = lp::assoc_bit<diepempmsk, 0, 16>;


    /* OTG_FS device control IN endpoint 0 control           register (OTG_FS_DIEPCTL0) */
    using fs_diepctl0 = lp::io_register<lp::u32_t, base_address + 0x100>;
    /* Maximum packet size */
    using fs_diepctl0_mpsiz = lp::assoc_bit<fs_diepctl0, 0, 2>;
    /* USB active endpoint */
    using fs_diepctl0_usbaep = lp::assoc_bit<fs_diepctl0, 15>;
    /* NAK status */
    using fs_diepctl0_naksts = lp::assoc_bit<fs_diepctl0, 17>;
    /* Endpoint type */
    using fs_diepctl0_eptyp = lp::assoc_bit<fs_diepctl0, 18, 2>;
    /* STALL handshake */
    using fs_diepctl0_stall = lp::assoc_bit<fs_diepctl0, 21>;
    /* TxFIFO number */
    using fs_diepctl0_txfnum = lp::assoc_bit<fs_diepctl0, 22, 4>;
    /* Clear NAK */
    using fs_diepctl0_cnak = lp::assoc_bit<fs_diepctl0, 26>;
    /* Set NAK */
    using fs_diepctl0_snak = lp::assoc_bit<fs_diepctl0, 27>;
    /* Endpoint disable */
    using fs_diepctl0_epdis = lp::assoc_bit<fs_diepctl0, 30>;
    /* Endpoint enable */
    using fs_diepctl0_epena = lp::assoc_bit<fs_diepctl0, 31>;


    /* OTG device endpoint-1 control           register */
    using diepctl1 = lp::io_register<lp::u32_t, base_address + 0x120>;
    /* EPENA */
    using diepctl1_epena = lp::assoc_bit<diepctl1, 31>;
    /* EPDIS */
    using diepctl1_epdis = lp::assoc_bit<diepctl1, 30>;
    /* SODDFRM/SD1PID */
    using diepctl1_soddfrm_sd1pid = lp::assoc_bit<diepctl1, 29>;
    /* SD0PID/SEVNFRM */
    using diepctl1_sd0pid_sevnfrm = lp::assoc_bit<diepctl1, 28>;
    /* SNAK */
    using diepctl1_snak = lp::assoc_bit<diepctl1, 27>;
    /* CNAK */
    using diepctl1_cnak = lp::assoc_bit<diepctl1, 26>;
    /* TXFNUM */
    using diepctl1_txfnum = lp::assoc_bit<diepctl1, 22, 4>;
    /* Stall */
    using diepctl1_stall = lp::assoc_bit<diepctl1, 21>;
    /* EPTYP */
    using diepctl1_eptyp = lp::assoc_bit<diepctl1, 18, 2>;
    /* NAKSTS */
    using diepctl1_naksts = lp::assoc_bit<diepctl1, 17>;
    /* EONUM/DPID */
    using diepctl1_eonum_dpid = lp::assoc_bit<diepctl1, 16>;
    /* USBAEP */
    using diepctl1_usbaep = lp::assoc_bit<diepctl1, 15>;
    /* MPSIZ */
    using diepctl1_mpsiz = lp::assoc_bit<diepctl1, 0, 11>;


    /* OTG device endpoint-2 control           register */
    using diepctl2 = lp::io_register<lp::u32_t, base_address + 0x140>;
    /* EPENA */
    using diepctl2_epena = lp::assoc_bit<diepctl2, 31>;
    /* EPDIS */
    using diepctl2_epdis = lp::assoc_bit<diepctl2, 30>;
    /* SODDFRM */
    using diepctl2_soddfrm = lp::assoc_bit<diepctl2, 29>;
    /* SD0PID/SEVNFRM */
    using diepctl2_sd0pid_sevnfrm = lp::assoc_bit<diepctl2, 28>;
    /* SNAK */
    using diepctl2_snak = lp::assoc_bit<diepctl2, 27>;
    /* CNAK */
    using diepctl2_cnak = lp::assoc_bit<diepctl2, 26>;
    /* TXFNUM */
    using diepctl2_txfnum = lp::assoc_bit<diepctl2, 22, 4>;
    /* Stall */
    using diepctl2_stall = lp::assoc_bit<diepctl2, 21>;
    /* EPTYP */
    using diepctl2_eptyp = lp::assoc_bit<diepctl2, 18, 2>;
    /* NAKSTS */
    using diepctl2_naksts = lp::assoc_bit<diepctl2, 17>;
    /* EONUM/DPID */
    using diepctl2_eonum_dpid = lp::assoc_bit<diepctl2, 16>;
    /* USBAEP */
    using diepctl2_usbaep = lp::assoc_bit<diepctl2, 15>;
    /* MPSIZ */
    using diepctl2_mpsiz = lp::assoc_bit<diepctl2, 0, 11>;


    /* OTG device endpoint-3 control           register */
    using diepctl3 = lp::io_register<lp::u32_t, base_address + 0x160>;
    /* EPENA */
    using diepctl3_epena = lp::assoc_bit<diepctl3, 31>;
    /* EPDIS */
    using diepctl3_epdis = lp::assoc_bit<diepctl3, 30>;
    /* SODDFRM */
    using diepctl3_soddfrm = lp::assoc_bit<diepctl3, 29>;
    /* SD0PID/SEVNFRM */
    using diepctl3_sd0pid_sevnfrm = lp::assoc_bit<diepctl3, 28>;
    /* SNAK */
    using diepctl3_snak = lp::assoc_bit<diepctl3, 27>;
    /* CNAK */
    using diepctl3_cnak = lp::assoc_bit<diepctl3, 26>;
    /* TXFNUM */
    using diepctl3_txfnum = lp::assoc_bit<diepctl3, 22, 4>;
    /* Stall */
    using diepctl3_stall = lp::assoc_bit<diepctl3, 21>;
    /* EPTYP */
    using diepctl3_eptyp = lp::assoc_bit<diepctl3, 18, 2>;
    /* NAKSTS */
    using diepctl3_naksts = lp::assoc_bit<diepctl3, 17>;
    /* EONUM/DPID */
    using diepctl3_eonum_dpid = lp::assoc_bit<diepctl3, 16>;
    /* USBAEP */
    using diepctl3_usbaep = lp::assoc_bit<diepctl3, 15>;
    /* MPSIZ */
    using diepctl3_mpsiz = lp::assoc_bit<diepctl3, 0, 11>;


    /* device endpoint-0 control           register */
    using doepctl0 = lp::io_register<lp::u32_t, base_address + 0x300>;
    /* EPENA */
    using doepctl0_epena = lp::assoc_bit<doepctl0, 31>;
    /* EPDIS */
    using doepctl0_epdis = lp::assoc_bit<doepctl0, 30>;
    /* SNAK */
    using doepctl0_snak = lp::assoc_bit<doepctl0, 27>;
    /* CNAK */
    using doepctl0_cnak = lp::assoc_bit<doepctl0, 26>;
    /* Stall */
    using doepctl0_stall = lp::assoc_bit<doepctl0, 21>;
    /* SNPM */
    using doepctl0_snpm = lp::assoc_bit<doepctl0, 20>;
    /* EPTYP */
    using doepctl0_eptyp = lp::assoc_bit<doepctl0, 18, 2>;
    /* NAKSTS */
    using doepctl0_naksts = lp::assoc_bit<doepctl0, 17>;
    /* USBAEP */
    using doepctl0_usbaep = lp::assoc_bit<doepctl0, 15>;
    /* MPSIZ */
    using doepctl0_mpsiz = lp::assoc_bit<doepctl0, 0, 2>;


    /* device endpoint-1 control           register */
    using doepctl1 = lp::io_register<lp::u32_t, base_address + 0x320>;
    /* EPENA */
    using doepctl1_epena = lp::assoc_bit<doepctl1, 31>;
    /* EPDIS */
    using doepctl1_epdis = lp::assoc_bit<doepctl1, 30>;
    /* SODDFRM */
    using doepctl1_soddfrm = lp::assoc_bit<doepctl1, 29>;
    /* SD0PID/SEVNFRM */
    using doepctl1_sd0pid_sevnfrm = lp::assoc_bit<doepctl1, 28>;
    /* SNAK */
    using doepctl1_snak = lp::assoc_bit<doepctl1, 27>;
    /* CNAK */
    using doepctl1_cnak = lp::assoc_bit<doepctl1, 26>;
    /* Stall */
    using doepctl1_stall = lp::assoc_bit<doepctl1, 21>;
    /* SNPM */
    using doepctl1_snpm = lp::assoc_bit<doepctl1, 20>;
    /* EPTYP */
    using doepctl1_eptyp = lp::assoc_bit<doepctl1, 18, 2>;
    /* NAKSTS */
    using doepctl1_naksts = lp::assoc_bit<doepctl1, 17>;
    /* EONUM/DPID */
    using doepctl1_eonum_dpid = lp::assoc_bit<doepctl1, 16>;
    /* USBAEP */
    using doepctl1_usbaep = lp::assoc_bit<doepctl1, 15>;
    /* MPSIZ */
    using doepctl1_mpsiz = lp::assoc_bit<doepctl1, 0, 11>;


    /* device endpoint-2 control           register */
    using doepctl2 = lp::io_register<lp::u32_t, base_address + 0x340>;
    /* EPENA */
    using doepctl2_epena = lp::assoc_bit<doepctl2, 31>;
    /* EPDIS */
    using doepctl2_epdis = lp::assoc_bit<doepctl2, 30>;
    /* SODDFRM */
    using doepctl2_soddfrm = lp::assoc_bit<doepctl2, 29>;
    /* SD0PID/SEVNFRM */
    using doepctl2_sd0pid_sevnfrm = lp::assoc_bit<doepctl2, 28>;
    /* SNAK */
    using doepctl2_snak = lp::assoc_bit<doepctl2, 27>;
    /* CNAK */
    using doepctl2_cnak = lp::assoc_bit<doepctl2, 26>;
    /* Stall */
    using doepctl2_stall = lp::assoc_bit<doepctl2, 21>;
    /* SNPM */
    using doepctl2_snpm = lp::assoc_bit<doepctl2, 20>;
    /* EPTYP */
    using doepctl2_eptyp = lp::assoc_bit<doepctl2, 18, 2>;
    /* NAKSTS */
    using doepctl2_naksts = lp::assoc_bit<doepctl2, 17>;
    /* EONUM/DPID */
    using doepctl2_eonum_dpid = lp::assoc_bit<doepctl2, 16>;
    /* USBAEP */
    using doepctl2_usbaep = lp::assoc_bit<doepctl2, 15>;
    /* MPSIZ */
    using doepctl2_mpsiz = lp::assoc_bit<doepctl2, 0, 11>;


    /* device endpoint-3 control           register */
    using doepctl3 = lp::io_register<lp::u32_t, base_address + 0x360>;
    /* EPENA */
    using doepctl3_epena = lp::assoc_bit<doepctl3, 31>;
    /* EPDIS */
    using doepctl3_epdis = lp::assoc_bit<doepctl3, 30>;
    /* SODDFRM */
    using doepctl3_soddfrm = lp::assoc_bit<doepctl3, 29>;
    /* SD0PID/SEVNFRM */
    using doepctl3_sd0pid_sevnfrm = lp::assoc_bit<doepctl3, 28>;
    /* SNAK */
    using doepctl3_snak = lp::assoc_bit<doepctl3, 27>;
    /* CNAK */
    using doepctl3_cnak = lp::assoc_bit<doepctl3, 26>;
    /* Stall */
    using doepctl3_stall = lp::assoc_bit<doepctl3, 21>;
    /* SNPM */
    using doepctl3_snpm = lp::assoc_bit<doepctl3, 20>;
    /* EPTYP */
    using doepctl3_eptyp = lp::assoc_bit<doepctl3, 18, 2>;
    /* NAKSTS */
    using doepctl3_naksts = lp::assoc_bit<doepctl3, 17>;
    /* EONUM/DPID */
    using doepctl3_eonum_dpid = lp::assoc_bit<doepctl3, 16>;
    /* USBAEP */
    using doepctl3_usbaep = lp::assoc_bit<doepctl3, 15>;
    /* MPSIZ */
    using doepctl3_mpsiz = lp::assoc_bit<doepctl3, 0, 11>;


    /* device endpoint-x interrupt           register */
    using diepint0 = lp::io_register<lp::u32_t, base_address + 0x108>;
    /* TXFE */
    using diepint0_txfe = lp::assoc_bit<diepint0, 7>;
    /* INEPNE */
    using diepint0_inepne = lp::assoc_bit<diepint0, 6>;
    /* ITTXFE */
    using diepint0_ittxfe = lp::assoc_bit<diepint0, 4>;
    /* TOC */
    using diepint0_toc = lp::assoc_bit<diepint0, 3>;
    /* EPDISD */
    using diepint0_epdisd = lp::assoc_bit<diepint0, 1>;
    /* XFRC */
    using diepint0_xfrc = lp::assoc_bit<diepint0, 0>;


    /* device endpoint-1 interrupt           register */
    using diepint1 = lp::io_register<lp::u32_t, base_address + 0x128>;
    /* TXFE */
    using diepint1_txfe = lp::assoc_bit<diepint1, 7>;
    /* INEPNE */
    using diepint1_inepne = lp::assoc_bit<diepint1, 6>;
    /* ITTXFE */
    using diepint1_ittxfe = lp::assoc_bit<diepint1, 4>;
    /* TOC */
    using diepint1_toc = lp::assoc_bit<diepint1, 3>;
    /* EPDISD */
    using diepint1_epdisd = lp::assoc_bit<diepint1, 1>;
    /* XFRC */
    using diepint1_xfrc = lp::assoc_bit<diepint1, 0>;


    /* device endpoint-2 interrupt           register */
    using diepint2 = lp::io_register<lp::u32_t, base_address + 0x148>;
    /* TXFE */
    using diepint2_txfe = lp::assoc_bit<diepint2, 7>;
    /* INEPNE */
    using diepint2_inepne = lp::assoc_bit<diepint2, 6>;
    /* ITTXFE */
    using diepint2_ittxfe = lp::assoc_bit<diepint2, 4>;
    /* TOC */
    using diepint2_toc = lp::assoc_bit<diepint2, 3>;
    /* EPDISD */
    using diepint2_epdisd = lp::assoc_bit<diepint2, 1>;
    /* XFRC */
    using diepint2_xfrc = lp::assoc_bit<diepint2, 0>;


    /* device endpoint-3 interrupt           register */
    using diepint3 = lp::io_register<lp::u32_t, base_address + 0x168>;
    /* TXFE */
    using diepint3_txfe = lp::assoc_bit<diepint3, 7>;
    /* INEPNE */
    using diepint3_inepne = lp::assoc_bit<diepint3, 6>;
    /* ITTXFE */
    using diepint3_ittxfe = lp::assoc_bit<diepint3, 4>;
    /* TOC */
    using diepint3_toc = lp::assoc_bit<diepint3, 3>;
    /* EPDISD */
    using diepint3_epdisd = lp::assoc_bit<diepint3, 1>;
    /* XFRC */
    using diepint3_xfrc = lp::assoc_bit<diepint3, 0>;


    /* device endpoint-0 interrupt           register */
    using doepint0 = lp::io_register<lp::u32_t, base_address + 0x308>;
    /* B2BSTUP */
    using doepint0_b2bstup = lp::assoc_bit<doepint0, 6>;
    /* OTEPDIS */
    using doepint0_otepdis = lp::assoc_bit<doepint0, 4>;
    /* STUP */
    using doepint0_stup = lp::assoc_bit<doepint0, 3>;
    /* EPDISD */
    using doepint0_epdisd = lp::assoc_bit<doepint0, 1>;
    /* XFRC */
    using doepint0_xfrc = lp::assoc_bit<doepint0, 0>;


    /* device endpoint-1 interrupt           register */
    using doepint1 = lp::io_register<lp::u32_t, base_address + 0x328>;
    /* B2BSTUP */
    using doepint1_b2bstup = lp::assoc_bit<doepint1, 6>;
    /* OTEPDIS */
    using doepint1_otepdis = lp::assoc_bit<doepint1, 4>;
    /* STUP */
    using doepint1_stup = lp::assoc_bit<doepint1, 3>;
    /* EPDISD */
    using doepint1_epdisd = lp::assoc_bit<doepint1, 1>;
    /* XFRC */
    using doepint1_xfrc = lp::assoc_bit<doepint1, 0>;


    /* device endpoint-2 interrupt           register */
    using doepint2 = lp::io_register<lp::u32_t, base_address + 0x348>;
    /* B2BSTUP */
    using doepint2_b2bstup = lp::assoc_bit<doepint2, 6>;
    /* OTEPDIS */
    using doepint2_otepdis = lp::assoc_bit<doepint2, 4>;
    /* STUP */
    using doepint2_stup = lp::assoc_bit<doepint2, 3>;
    /* EPDISD */
    using doepint2_epdisd = lp::assoc_bit<doepint2, 1>;
    /* XFRC */
    using doepint2_xfrc = lp::assoc_bit<doepint2, 0>;


    /* device endpoint-3 interrupt           register */
    using doepint3 = lp::io_register<lp::u32_t, base_address + 0x368>;
    /* B2BSTUP */
    using doepint3_b2bstup = lp::assoc_bit<doepint3, 6>;
    /* OTEPDIS */
    using doepint3_otepdis = lp::assoc_bit<doepint3, 4>;
    /* STUP */
    using doepint3_stup = lp::assoc_bit<doepint3, 3>;
    /* EPDISD */
    using doepint3_epdisd = lp::assoc_bit<doepint3, 1>;
    /* XFRC */
    using doepint3_xfrc = lp::assoc_bit<doepint3, 0>;


    /* device endpoint-0 transfer size           register */
    using dieptsiz0 = lp::io_register<lp::u32_t, base_address + 0x110>;
    /* Packet count */
    using dieptsiz0_pktcnt = lp::assoc_bit<dieptsiz0, 19, 2>;
    /* Transfer size */
    using dieptsiz0_xfrsiz = lp::assoc_bit<dieptsiz0, 0, 7>;


    /* device OUT endpoint-0 transfer size           register */
    using doeptsiz0 = lp::io_register<lp::u32_t, base_address + 0x310>;
    /* SETUP packet count */
    using doeptsiz0_stupcnt = lp::assoc_bit<doeptsiz0, 29, 2>;
    /* Packet count */
    using doeptsiz0_pktcnt = lp::assoc_bit<doeptsiz0, 19>;
    /* Transfer size */
    using doeptsiz0_xfrsiz = lp::assoc_bit<doeptsiz0, 0, 7>;


    /* device endpoint-1 transfer size           register */
    using dieptsiz1 = lp::io_register<lp::u32_t, base_address + 0x130>;
    /* Multi count */
    using dieptsiz1_mcnt = lp::assoc_bit<dieptsiz1, 29, 2>;
    /* Packet count */
    using dieptsiz1_pktcnt = lp::assoc_bit<dieptsiz1, 19, 10>;
    /* Transfer size */
    using dieptsiz1_xfrsiz = lp::assoc_bit<dieptsiz1, 0, 19>;


    /* device endpoint-2 transfer size           register */
    using dieptsiz2 = lp::io_register<lp::u32_t, base_address + 0x150>;
    /* Multi count */
    using dieptsiz2_mcnt = lp::assoc_bit<dieptsiz2, 29, 2>;
    /* Packet count */
    using dieptsiz2_pktcnt = lp::assoc_bit<dieptsiz2, 19, 10>;
    /* Transfer size */
    using dieptsiz2_xfrsiz = lp::assoc_bit<dieptsiz2, 0, 19>;


    /* device endpoint-3 transfer size           register */
    using dieptsiz3 = lp::io_register<lp::u32_t, base_address + 0x170>;
    /* Multi count */
    using dieptsiz3_mcnt = lp::assoc_bit<dieptsiz3, 29, 2>;
    /* Packet count */
    using dieptsiz3_pktcnt = lp::assoc_bit<dieptsiz3, 19, 10>;
    /* Transfer size */
    using dieptsiz3_xfrsiz = lp::assoc_bit<dieptsiz3, 0, 19>;


    /* OTG_FS device IN endpoint transmit FIFO           status register */
    using dtxfsts0 = lp::io_register<lp::u32_t, base_address + 0x118>;
    /* IN endpoint TxFIFO space               available */
    using dtxfsts0_ineptfsav = lp::assoc_bit<dtxfsts0, 0, 16>;


    /* OTG_FS device IN endpoint transmit FIFO           status register */
    using dtxfsts1 = lp::io_register<lp::u32_t, base_address + 0x138>;
    /* IN endpoint TxFIFO space               available */
    using dtxfsts1_ineptfsav = lp::assoc_bit<dtxfsts1, 0, 16>;


    /* OTG_FS device IN endpoint transmit FIFO           status register */
    using dtxfsts2 = lp::io_register<lp::u32_t, base_address + 0x158>;
    /* IN endpoint TxFIFO space               available */
    using dtxfsts2_ineptfsav = lp::assoc_bit<dtxfsts2, 0, 16>;


    /* OTG_FS device IN endpoint transmit FIFO           status register */
    using dtxfsts3 = lp::io_register<lp::u32_t, base_address + 0x178>;
    /* IN endpoint TxFIFO space               available */
    using dtxfsts3_ineptfsav = lp::assoc_bit<dtxfsts3, 0, 16>;


    /* device OUT endpoint-1 transfer size           register */
    using doeptsiz1 = lp::io_register<lp::u32_t, base_address + 0x330>;
    /* Received data PID/SETUP packet               count */
    using doeptsiz1_rxdpid_stupcnt = lp::assoc_bit<doeptsiz1, 29, 2>;
    /* Packet count */
    using doeptsiz1_pktcnt = lp::assoc_bit<doeptsiz1, 19, 10>;
    /* Transfer size */
    using doeptsiz1_xfrsiz = lp::assoc_bit<doeptsiz1, 0, 19>;


    /* device OUT endpoint-2 transfer size           register */
    using doeptsiz2 = lp::io_register<lp::u32_t, base_address + 0x350>;
    /* Received data PID/SETUP packet               count */
    using doeptsiz2_rxdpid_stupcnt = lp::assoc_bit<doeptsiz2, 29, 2>;
    /* Packet count */
    using doeptsiz2_pktcnt = lp::assoc_bit<doeptsiz2, 19, 10>;
    /* Transfer size */
    using doeptsiz2_xfrsiz = lp::assoc_bit<doeptsiz2, 0, 19>;


    /* device OUT endpoint-3 transfer size           register */
    using doeptsiz3 = lp::io_register<lp::u32_t, base_address + 0x370>;
    /* Received data PID/SETUP packet               count */
    using doeptsiz3_rxdpid_stupcnt = lp::assoc_bit<doeptsiz3, 29, 2>;
    /* Packet count */
    using doeptsiz3_pktcnt = lp::assoc_bit<doeptsiz3, 19, 10>;
    /* Transfer size */
    using doeptsiz3_xfrsiz = lp::assoc_bit<doeptsiz3, 0, 19>;


};

/* USB on the go full speed */
template <lp::addr_t base_address>
struct otg_fs_pwrclk_t {
    /* OTG_FS power and clock gating control           register (OTG_FS_PCGCCTL) */
    using fs_pcgcctl = lp::io_register<lp::u32_t, base_address + 0x0>;
    /* Stop PHY clock */
    using fs_pcgcctl_stppclk = lp::assoc_bit<fs_pcgcctl, 0>;
    /* Gate HCLK */
    using fs_pcgcctl_gatehclk = lp::assoc_bit<fs_pcgcctl, 1>;
    /* PHY Suspended */
    using fs_pcgcctl_physusp = lp::assoc_bit<fs_pcgcctl, 4>;


};

using otg_fs_global = otg_fs_global_t<0x50000000>;
using otg_fs_host = otg_fs_host_t<0x50000400>;
using otg_fs_device = otg_fs_device_t<0x50000800>;
using otg_fs_pwrclk = otg_fs_pwrclk_t<0x50000e00>;

#endif // USB_OTG_FS_HH
