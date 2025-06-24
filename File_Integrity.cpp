#include <iostream>
#include <unistd.h>
#include <sys/inotify.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

void printEvent(struct inotify_event *event)
{
    if (event->len)
    {
        if (event->mask & IN_CREATE)
            std::cout << "Created: " << event->name << std::endl;
        if (event->mask & IN_DELETE)
            std::cout << "Deleted: " << event->name << std::endl;
        if (event->mask & IN_MODIFY)
            std::cout << "Modified: " << event->name << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <directory_to_watch>" << std::endl;
        return 1;
    }

    const char *path = argv[1];
    int fd = inotify_init();

    if (fd < 0)
    {
        perror("inotify_init");
        return 1;
    }

    int wd = inotify_add_watch(fd, path, IN_CREATE | IN_DELETE | IN_MODIFY);

    if (wd == -1)
    {
        std::cerr << "Cannot watch directory: " << path << std::endl;
        perror("inotify_add_watch");
        close(fd);
        return 1;
    }

    std::cout << "Monitoring changes in: " << path << std::endl;

    char buffer[BUF_LEN];

    while (true)
    {
        int length = read(fd, buffer, BUF_LEN);

        if (length < 0)
        {
            perror("read");
            break;
        }

        int i = 0;
        while (i < length)
        {
            struct inotify_event *event = (struct inotify_event *)&buffer[i];
            printEvent(event);
            i += EVENT_SIZE + event->len;
        }
    }

    inotify_rm_watch(fd, wd);
    close(fd);

    return 0;
}