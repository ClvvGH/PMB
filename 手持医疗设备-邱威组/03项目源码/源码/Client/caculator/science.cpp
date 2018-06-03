#include "science.h"
#include "ui_science.h"

SCIENCE::SCIENCE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCIENCE)
{
    ui->setupUi(this);
}

SCIENCE::~SCIENCE()
{
    delete ui;
}


void SCIENCE::on_pushButton_1_clicked()
{
    TEMP+='1';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_2_clicked()
{
    TEMP+='2';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_3_clicked()
{
    TEMP+='3';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_4_clicked()
{
    TEMP+='4';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_clicked()
{
    TEMP+='5';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_5_clicked()
{
    TEMP+='6';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_6_clicked()
{
    TEMP+='7';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_7_clicked()
{
    TEMP+='8';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_8_clicked()
{
    TEMP+='9';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

void SCIENCE::on_pushButton_10_clicked()
{
    TEMP+='0';
    ui->lineEdit_input->setText(TEMP);
    num=TEMP.toDouble();
}

//清屏
void SCIENCE::on_pushButton_clean_clicked()
{
    num=0;
    TEMP="";
    result=0;
    ui->lineEdit_input->setText(TEMP);
    ui->lineEdit_output->setText(TEMP);
}
//。
void SCIENCE::on_pushButton_POINT_clicked()
{
    TEMP+='.';
    ui->lineEdit_input->setText(TEMP);
}

//平方
void SCIENCE::on_pushButton_pingfang_clicked()
{
    FLAG=1;
    ui->lineEdit_input->setText(TEMP+"^2");

}
//立方
void SCIENCE::on_pushButton_lifang_clicked()
{
    FLAG=2;
    ui->lineEdit_input->setText(TEMP+"^3");
}
//阶乘
void SCIENCE::on_pushButton_jiecheng_clicked()
{
  FLAG=3;
  ui->lineEdit_input->setText(TEMP+"！");
}
//正弦
void SCIENCE::on_pushButton_zhengxian_clicked()
{
     FLAG=4;
      ui->lineEdit_input->setText("Sin"+TEMP);
}
//余弦
void SCIENCE::on_pushButton_yuxian_clicked()
{
     FLAG=5;
     ui->lineEdit_input->setText("Cos"+TEMP);
}
//正切
void SCIENCE::on_pushButton_zhengqie_clicked()
{
    FLAG=6;
     ui->lineEdit_input->setText("Tan"+TEMP);
}
//指数 x^y
void SCIENCE::on_pushButton_zhishu_clicked()
{
   FLAG=7;
   ui->lineEdit_input->setText(TEMP+"^");
   FIRST=num;
   num=0;
   TEMP="";
}
//导数 Ln X
void SCIENCE::on_pushButton_daoshu_clicked()
{
  FLAG=8;
  ui->lineEdit_input->setText("Ln"+TEMP);
}
//平方根
void SCIENCE::on_pushButton_GEN_clicked()
{
    FLAG=9;
    ui->lineEdit_input->setText("√"+TEMP);
}


void SCIENCE::on_pushButton_EQUAL_clicked()
{
    SECOND=num;
    switch (FLAG)
    {
         //平方
         case 1 :
         result=num*num;
         break;

         // 立方
         case 2 :
         result=num*num*num;
         break;

         // 阶乘
         case 3 :
          int i;
          result=1;
          for(i=1;i<=num;i++)
          {
              result=result*i;
          }
         break;

          //正弦   sin
         case 4:
         result = qSin(num);
         break;

         //余弦  cos
        case 5:
        result = qCos(num);
        break;

        //正切  tan
        case 6:
        result = qTan(num);
        break;

        //x^y
         case 7:
         result=qPow(FIRST,SECOND);
         break;

        //Ln X
        case 8:
        result=qLn(num);
        break;

        //√x
        case 9:
        result=sqrt(num);
    }

    QString jieguo =QString::number(result);
    ui->lineEdit_output->setText(jieguo);
}

