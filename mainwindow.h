#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "n4d.h"

#include <QDebug>
#include <QThread>
#include <QStandardItemModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QRegularExpression>
#include <QTableWidget>

#include <algorithm>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void ProcessCallback(QtN4DWorker::Methods, QString returned, int serial);
    void InitValidation();
    void InitCheckStatus();
    void InitGetQuotaGroups();
    void InitGetCurrentQuotas();
    void InitGetGolemGroups();
    void PopulateGroupTableWithFilter();
    void PopulateUserTableWithFilter();
    void ResetGroupTable();
    void ResetUserTable();
    void GoToResume();
    void CellChangedUserTable(int row,int col);
    void CellChangedGroupTable(int row, int col);
    void PendingBack();
    void SwitchUserEdition();
    void SwitchGroupEdition();
    void Enable();
    void Disable();
    void removeThread(int i);
    void PendingApply();

private:
    Ui::MainWindow *ui;

    // System structures
    QMap<int,QThread*> local_thread;
    QString n4duser, n4dpwd;
    QMap<QtN4DWorker::Methods,bool> completedTasks;
    QList<QWidget*> last_page_used;
    QList<QTableWidget*> tablewidgets;
    QStringList golem_groups;
    QMap<QTableWidget*,bool> enable_watch_table;
    QMap<QTableWidget*,QStringList> non_editable_columns;
    QMap<QTableWidget*,QMap<QString,QStringList>*> modelmap;
    QMap<QTableWidget*,bool> pending_changes;
    QList<QStringList> changes_to_apply;

    void init_structures(bool init_threads);
    void destroy_structures(bool init_threads);

    void InitN4DCall(QtN4DWorker::Methods method);
    void InitN4DCall(QtN4DWorker::Methods method, QStringList params);
    void runWhenCompletedTask();

    void CheckValidation(QString result); //cb InitValidation
    void CompleteGetData(QString result); //cb GET_DATA
    void CompleteGetStatus(QString result); //cb CheckStatus
    void CompleteGetConfigure(QString result); //cb InitGetQuotaGroups
    void StoreGolemGroups(QString result); //cb GetGolemGroups
    void SystemIsEnabled(QString result); //cb Enable
    void SystemIsDisabled(QString result); //cb Disable
    void AddedUserQuota(QString result); //cb set userquota
    void AddedGroupQuota(QString result); //cb set groupquota

    void PrepareTableMaps();
    void ChangePannel(QWidget* pannel);
    void InitializeTable(QTableWidget* item);
    void makeReadOnlyTable(QTableWidget* table);
    void PopulateTableWithFilters(QTableWidget* table, QStringList showfilter, QStringList filter, QLineEdit* txtfilter, bool overwrite);
    void PopulateTable(QMap<QString,QStringList>* data, QTableWidget* table);
    void PopulateTable(QMap<QString,QStringList>* data, QTableWidget* table, QStringList showfilter, QStringList filter);
    QMap<QString,QStringList> readViewTable(QTableWidget* table);
    QMap<QString,QStringList> getTableDifferences(QMap<QString,QStringList>* td1,QMap<QString,QStringList>* td2);
    QMap<QString,QStringList> getTableDifferencesWithHeader(QMap<QString,QStringList>* td1,QMap<QString,QStringList>* td2);
    QMap<QString,QStringList> ApplyChangesToModel(QMap<QString,QStringList>* model,QMap<QString,QStringList>* changes);
    bool MakeSameCols(QMap<QString,QStringList> &model,QMap<QString,QStringList> &changes);
    bool isModified(QMap<QString,QStringList>* td1,QMap<QString,QStringList>* td2);
    void showConfirmationTable();

    QString normalizeUnits(QString value);
    QString denormalizeUnits(QString value);
    bool isValidQuotaValue(QString value);
    void CellChanged(int row, int col, QTableWidget* table);
    bool checkApplyButtons();
};

#endif // MAINWINDOW_H
