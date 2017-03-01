/*
 *	File: decent_wallet_ui_gui_contentdetailsgeneral.cpp
 *
 *	Created on: 21 Feb 2017
 *	Created by: Davit Kalantaryan (Email: davit.kalantaryan@desy.de)
 *
 *  This file implements ...
 *
 */


#include "decent_wallet_ui_gui_contentdetailsgeneral.hpp"
#include <QMouseEvent>

// Implemented in 'gui_wallet_centralwigdet.cpp'
std::string FindImagePath(bool& a_bRet,const char* a_image_name);


decent::wallet::ui::gui::ContentDetailsGeneral::ContentDetailsGeneral()
    :
      m_label(this,NULL,&decent::wallet::ui::gui::ContentDetailsGeneral::LabelPushCallbackGUI)
{
    bool bRet;
 //   std::string sImagePath = FindImagePath(bRet,":/icon/images/buy_button_image.png");
    QPixmap aPixMap(":/icon/images/buy_button_image.png");
    m_label.setScaledContents(true);
    m_label.setPixmap(aPixMap);
    m_free_for_child.addWidget(&m_label);
    setFixedSize(397,381);
}


decent::wallet::ui::gui::ContentDetailsGeneral::~ContentDetailsGeneral()
{
    //
}


void decent::wallet::ui::gui::ContentDetailsGeneral::execCDD(
        const decent::wallet::ui::gui::SDigitalContent& a_cnt_details)
{
    execCDB(a_cnt_details);
}

#include <QMessageBox>

void decent::wallet::ui::gui::ContentDetailsGeneral::LabelPushCallbackGUI(void*,QMouseEvent* a_mouse_event)
{

    QString aCont = tr("mouse clich on: [x=") + QString::number(a_mouse_event->pos().x()) + tr(";y=") +
            QString::number(a_mouse_event->pos().y()) + tr("];");

    QString aDetails = tr("Overload function ") + tr(__FUNCTION__) +
            tr("\nFrom file \"") + tr(__SOURCE_FILE__) +
            tr("\",line=") + QString::number(__LINE__,10);

    QMessageBox aMessageBox(QMessageBox::Warning,
                            QObject::tr("should be modified!"),aCont,
                            QMessageBox::Ok,this);
    //aMessageBox.setStyleSheet(QMessageBox::);
    aMessageBox.setDetailedText(aDetails);

    aMessageBox.setFixedSize(200,100);
    //aMessageBox.setStyleSheet("");
    aMessageBox.setStyleSheet("QLabel{min-width: 300px;}");

    aMessageBox.exec();
}
