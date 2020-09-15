#pragma once

#ifndef __DB_CONNECTOR_HPP__
#define __DB_CONNECTOR_HPP__

#include <mariadb++/connection.hpp>
#include <vector>

namespace db {
    ///database connect env
    namespace env { 
        constexpr static const char* host = "localhost";
        constexpr static const uint32_t port = 3306;
        constexpr static const char* user = "";
        constexpr static const char* password = ""; 
        constexpr static const char* database = "gp2020fall"; //unused variable
        constexpr static const char* socket = ""; //unused variable
    }

    struct PrivateSet {
        std::string value;
        uint frequency;
        float amount;
    };
    const std::string search_infector_query(const std::string &table);
    std::vector<PrivateSet> query_to_vec(mariadb::result_set_ref result);

    class Connector {
    public:
        Connector(const std::string& table_name);
        Connector& setup(); /// db connet and setting (db auto start, connection, create database, table)
        inline mariadb::connection_ref& con() { return con_; } ///< database connector (smartpointer use ->) 
        inline const std::string table_name() { return table_name_; }
    private:
        mariadb::connection_ref con_;
        mariadb::account_ref acc_;
        std::string table_name_;
    };
}


#endif