/*
 * Copyright (c) 2012 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_TrainDB_h
#define _GC_TrainDB_h 1

#include "GoldenCheetah.h"
#include <QMessageBox>
#include <QDir>
#include <QHash>
#include <QtSql>

class ErgFile;
class TrainDB
{

	public:

    // get connection name
    QSqlDatabase connection() { return dbconn; }

    // check the db structure is up to date
    void checkDBVersion();

    // get schema version
    int getDBVersion();

    // create and drop connections
	TrainDB(QDir home);
    ~TrainDB();

    bool importWorkout(QString pathname, ErgFile *ergFile);
    bool importVideo(QString pathname); //XXX simple for now

	private:
        QDir home;
        QSqlDatabase db;
        QSqlDatabase dbconn;

	    void initDatabase(QDir home);
	    bool createDatabase();
        void closeConnection();
        bool createWorkoutTable();
        bool dropWorkoutTable();
        bool createVideoTable();
        bool dropVideoTable();
};

extern TrainDB *trainDB;
#endif