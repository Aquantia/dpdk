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
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
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
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
 * Enable MACsec offload.
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @param encr
 *    1 - Enable encryption (encrypt and add integrity signature).
 *    0 - Disable encryption (only add integrity signature).
 * @param repl_prot
 *    1 - Enable replay protection.
 *    0 - Disable replay protection.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 */
__rte_experimental
int rte_pmd_atl_macsec_enable(uint16_t port, uint8_t encr, uint8_t repl_prot);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
 * Disable MACsec offload.
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 */
__rte_experimental
int rte_pmd_atl_macsec_disable(uint16_t port);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
 * Configure Tx SC (Secure Connection).
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @param mac
 *   The MAC address on the local side.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 */
__rte_experimental
int rte_pmd_atl_macsec_config_txsc(uint16_t port, uint8_t *mac);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
 * Configure Rx SC (Secure Connection).
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @param mac
 *   The MAC address on the remote side.
 * @param pi
 *   The PI (port identifier) on the remote side.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 */
__rte_experimental
int rte_pmd_atl_macsec_config_rxsc(uint16_t port, uint8_t *mac, uint16_t pi);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
 * Enable Tx SA (Secure Association).
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @param idx
 *   The SA to be enabled (0 or 1).
 * @param an
 *   The association number on the local side.
 * @param pn
 *   The packet number on the local side.
 * @param key
 *   The key on the local side.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 *   - (-EINVAL) if bad parameter.
 */
__rte_experimental
int rte_pmd_atl_macsec_select_txsa(uint16_t port, uint8_t idx, uint8_t an,
				   uint32_t pn, uint8_t *key);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice
 *
 * Enable Rx SA (Secure Association).
 *
 * @param port
 *   The port identifier of the Ethernet device.
 * @param idx
 *   The SA to be enabled (0 or 1)
 * @param an
 *   The association number on the remote side.
 * @param pn
 *   The packet number on the remote side.
 * @param key
 *   The key on the remote side.
 * @return
 *   - (0) if successful.
 *   - (-ENODEV) if *port* invalid.
 *   - (-ENOTSUP) if hardware doesn't support this feature.
 *   - (-EINVAL) if bad parameter.
 */
__rte_experimental
int rte_pmd_atl_macsec_select_rxsa(uint16_t port, uint8_t idx, uint8_t an,
				   uint32_t pn, uint8_t *key);

#endif /* _PMD_ATLANTIC_H_ */
