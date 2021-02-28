// Copyright (c) 2017-2019 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZCORRCONTROLDIALOG_H
#define ZCORRCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zcorr/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZCorrControlDialog;
}

class CZCorrControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZCorrControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZCorrControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZCorrControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZCorrControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZCorrControlDialog(QWidget *parent);
    ~ZCorrControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZCorrControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZCorrControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZCORRCONTROLDIALOG_H
