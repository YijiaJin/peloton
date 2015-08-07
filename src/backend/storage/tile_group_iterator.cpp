//===----------------------------------------------------------------------===//
//
//                         PelotonDB
//
// tile_group_iterator.cpp
//
// Identification: src/backend/storage/tile_group_iterator.cpp
//
// Copyright (c) 2015, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "backend/storage/tile_group_iterator.h"

namespace peloton {
namespace storage {

bool TileGroupIterator::Next(std::shared_ptr<TileGroup> &tileGroup) {
  if (HasNext()) {
    std::shared_ptr<TileGroup> next(table_->GetTileGroup(tileGroupItr_));
    tileGroup.swap(next);
    return (true);
  }
  return (false);
}

bool TileGroupIterator::HasNext() {
  return (tileGroupItr_ < table_->GetTileGroupCount());
}

}  // End storage namespace
}  // End peloton namespace