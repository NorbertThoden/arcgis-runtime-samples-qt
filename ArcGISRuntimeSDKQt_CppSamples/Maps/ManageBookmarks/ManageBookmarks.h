// [WriteFile Name=ManageBookmarks, Category=Maps]
// [Legal]
// Copyright 2016 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// [Legal]

#ifndef MANAGE_BOOKMARKS_H
#define MANAGE_BOOKMARKS_H

namespace Esri
{
  namespace ArcGISRuntime
  {
    class Map;
    class MapQuickView;
    class Viewpoint;
    class BookmarkListModel;
  }
}

class QStringList;
class QString;

#include <QQuickItem>

class ManageBookmarks : public QQuickItem
{
  Q_OBJECT
  //! [Expose the list model to QML]
  Q_PROPERTY(Esri::ArcGISRuntime::BookmarkListModel* bookmarks READ bookmarks NOTIFY bookmarksChanged)
  //! [Expose the list model to QML]

public:
  explicit ManageBookmarks(QQuickItem* parent = nullptr);
  ~ManageBookmarks();

  void componentComplete() Q_DECL_OVERRIDE;
  static void init();
  Q_INVOKABLE void goToBookmark(int bookmarkIndex);
  Q_INVOKABLE void addBookmark(QString newBookmarkName);

signals:
  void bookmarksChanged();

private:
  void createInitialBookmarks();
  void createBookmark(QString name, Esri::ArcGISRuntime::Viewpoint viewpoint);
  Esri::ArcGISRuntime::BookmarkListModel* bookmarks() const;

private:
  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
  Esri::ArcGISRuntime::BookmarkListModel* m_bookmarks = nullptr;
};

#endif // MANAGE_BOOKMARKS_H

