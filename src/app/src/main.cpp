#include <git2/repository.h>
#include <QDebug>
#include <iostream>
#include <regex>
#include "git2pp.h"

/**
 * \brief Main function
 * \param argc Number of arguments
 * \param argv arguments
 * \return
 */
int main(const int argc, char** argv) {
    git2pp::Session git2;
    try {
        auto repo = git2[git_repository_open](".");  // Exception on failure.
    } catch (const git2pp::Error& e) {
        qDebug() << e.what();
    }
    return 0;
}
