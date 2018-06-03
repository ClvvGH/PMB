#include "widget.h"
#include "ui_widget.h"
#include <time.h>
#include "science.h"

#include <QTextCodec>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    count=0;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

}

Widget::~Widget()
{
    delete ui;
}

//num 1
void Widget::on_pushButton_clicked()
{
   temp+='1';

   ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_2_clicked()
{
    temp+='2';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_3_clicked()
{
    temp+='3';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_4_clicked()
{
    temp+='4';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_5_clicked()
{
    temp+='5';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_6_clicked()
{
    temp+='6';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_7_clicked()
{
    temp+='7';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_8_clicked()
{
    temp+='8';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}

void Widget::on_pushButton_9_clicked()
{
    temp+='9';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}
//num 0
void Widget::on_pushButton_10_clicked()
{
    temp+='0';
    ui->lineEdit->setText(temp);
    num=temp.toDouble();
}
// .
void Widget::on_pushButton_point_clicked()
{
    temp+='.';
    ui->lineEdit->setText(temp);

}
// =
void Widget::on_pushButton_equal_clicked()
{

    SECOND=num;
    if(count==0)
    {
        flag2=str+temp+'=';
        ui->lineEdit->setText(flag2);
    }
    else
     {
        ui->lineEdit->setText(np+flag+temp+"=");

    }
    switch(flag)
    {
        case '+':
        RESULT=FIRST+SECOND;
        count++;
        break;

        case '-':

        RESULT=FIRST-SECOND;
        count++;
        break;

        case '*':
        RESULT=FIRST*SECOND;
         count++;

        break;

         case '/':
         if(SECOND != 0)  RESULT=FIRST/SECOND;
         else              flag3=0;        //除数不为0
         count++;
         break;


    }

    if(flag3==0)
    {
        ui->lineEdit_2->setText(tr("除数不能为0"));
        ui->lineEdit->clear();
        temp="";
        FIRST=0;
        SECOND=0;
        RESULT=0;
        flag3=1;
    }
    else
    {
        QString mp =QString::number(RESULT);
        ui->lineEdit_2->setText(mp);
        num=RESULT;         //将结果赋值给第一个值留待第二次计算
        np=mp;
    }

}
//+
void Widget::on_pushButton_Add_clicked()
{

    flag='+';
    flag1= QString(QChar(flag));
    str=ui->lineEdit->text()+flag1;
    ui->lineEdit->setText(str);
    FIRST=num;
    num=0;
    temp="";

}
//-
void Widget::on_pushButton_subtract_clicked()
{
    flag='-';
    flag1= QString(QChar(flag));
    str=ui->lineEdit->text()+flag1;
    ui->lineEdit->setText(str);
    FIRST=num;
    num=0;
    temp="";

}
//*
void Widget::on_pushButton_multiply_clicked()
{
    flag='*';
    flag1= QString(QChar(flag));
    str=ui->lineEdit->text()+flag1;
    ui->lineEdit->setText(str);
    FIRST=num;
    num=0;
    temp="";

}
// /
void Widget::on_pushButton_divide_clicked()
{
    flag='/';
    flag1= QString(QChar(flag));
    str=ui->lineEdit->text()+flag1;
    ui->lineEdit->setText(str);
    FIRST=num;
    num=0;
    temp="";

}
//清空屏幕输入输出框内容
void Widget::on_pushButton_clean_clicked()
{
    num=0;
    temp="";
    FIRST=0;
    SECOND=0;
    RESULT=0;
    count=0;
    ui->lineEdit->setText(temp);
    ui->lineEdit_2->setText(temp);
}
//删除上一个操作或者数字
void Widget::on_pushButton_delete_clicked()
{
   temp=temp.left(temp.length()-1);//减去一字符
   ui->lineEdit->setText(temp);
}
//获取当前时间
void Widget::on_pushButton_time_clicked()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    ui->lineEdit_2->setText(strr);
}
 //负数
void Widget::on_pushButton_11_clicked()
{
   temp = '-'+temp;
   ui->lineEdit->setText(temp);
}
//转到科学计算器页面
void Widget::on_pushButton_SCIENCE_clicked()
{
    SCIENCE *sci =new SCIENCE (this);
    sci->show();
}
//转到程序员计算器页面
void Widget::on_pushButton_JINZHI_clicked()
{

}
