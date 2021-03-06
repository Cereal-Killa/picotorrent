#pragma once

#include <QAbstractListModel>

#include <vector>

#include <libtorrent/fwd.hpp>

namespace pt
{
    class TorrentHandle;

    class TrackersListModel : public QAbstractListModel
    {
    public:
        enum Columns
        {
            Url,
            Status,
            Fails,
            NextAnnounce,
            _Max
        };

        TrackersListModel();
        virtual ~TrackersListModel();

        void clear();
        void update(TorrentHandle* torrent);

        int columnCount(const QModelIndex&) const override;
        QVariant data(const QModelIndex&, int role) const override;
        QVariant headerData(int section, Qt::Orientation, int role) const override;
        QModelIndex parent(const QModelIndex&);
        int rowCount(const QModelIndex&) const override;

    private:
        std::vector<libtorrent::announce_entry> m_trackers;
    };
}
