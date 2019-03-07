/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2018 Aquantia Corporation
 */

/**
 * @file rte_pmd_atlantic.h
 * atlantic PMD specific functions.
 *
 **/

#ifndef _PMD_ATLANTIC_H_
#define _PMD_ATLANTIC_H_

#include <rte_ethdev_driver.h>

#define RTE_PMD_AQ_HW_LED_OFF		0x3U
#define RTE_PMD_AQ_HW_LED_BLINK		0x2U
#define RTE_PMD_AQ_HW_LED_ON		0x1U
#define RTE_PMD_AQ_HW_LED_DEFAULT	0x0U

/**
 * This is a custom API for adapter's LED controls.
 *
 * @param dev
 *   Ethernet device to apply control to
 * @param control
 *   6 bit value (3 leds each 2bit):
 *   - bits 0-1: LED0 control
 *   - bits 2-3: LED1 control
 *   - bits 4-5: LED2 control
 *   Each two bit control value is:
 *   - 0: Firmware manages this LED activity
 *   - 1: Permanent ON
 *   - 2: Blinking
 *   - 3: Permanent OFF
 *
 * @return
 *   - (0) if successful.
 *   - (-ENOTSUP) if hardware doesn't support.
 */
int rte_pmd_atl_dev_led_control(int port, int control);

/**
 * Enable MACsec offload.
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @param en
 *    1 - Enable encryption (encrypt and add integrity signature).
 *    0 - Disable encryption (only add integrity signature).
 * @param rp
 *    1 - Enable replay protection.
 *    0 - Disable replay protection.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 */
int rte_pmd_atl_macsec_enable(uint16_t port, uint8_t en, uint8_t rp);
int rte_pmd_atl_macsec_disable(uint16_t port);
int rte_pmd_atl_macsec_config_txsc(uint16_t port, uint8_t *mac);
int rte_pmd_atl_macsec_config_rxsc(uint16_t port, uint8_t *mac, uint16_t pi);
int rte_pmd_atl_macsec_select_txsa(uint16_t port, uint8_t idx, uint8_t an, uint32_t pn, uint8_t *key);
int rte_pmd_atl_macsec_select_rxsa(uint16_t port, uint8_t idx, uint8_t an, uint32_t pn, uint8_t *key);


#endif /* _PMD_ATLANTIC_H_ */
