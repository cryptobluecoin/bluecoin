// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BLUECOIN_QT_BLUECOINADDRESSVALIDATOR_H
#define BLUECOIN_QT_BLUECOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BluecoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BluecoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Bluecoin address widget validator, checks for a valid bluecoin address.
 */
class BluecoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BluecoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // BLUECOIN_QT_BLUECOINADDRESSVALIDATOR_H
