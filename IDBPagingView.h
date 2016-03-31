//
//  IDBPagingView.h
//

/*
 from https://github.com/squarezw/ZWSlideViewController.git
 */

#import <UIKit/UIKit.h>

@interface IDBPage : UIView {
    NSUInteger _index;
}

@property(nonatomic, strong) UIView *contentView;

@end

@protocol IDBPagingViewDelegate;
@protocol IDBPagingViewDataSource;

@interface IDBPagingView : UIScrollView<UIScrollViewDelegate> {
    BOOL _scrollInfinitelyEnabled;

    NSUInteger _numberOfPages;

    NSMutableSet *_visiblePages;
    NSMutableSet *_recycledPages;

    IDBPage *_centerPage;

    __weak id<IDBPagingViewDelegate> _pagingDelegate;
    __weak id<IDBPagingViewDataSource> _pagingDataSource;

    __weak id _actualDelegate;
}

@property(nonatomic, assign) BOOL scrollInfinitelyEnabled;

@property(nonatomic, weak) id<IDBPagingViewDelegate> pagingDelegate;
@property(nonatomic, weak) id<IDBPagingViewDataSource> pagingDataSource;

@property(nonatomic, readonly) IDBPage *centerPage;
@property(nonatomic, readonly) NSSet *visiblePages;

- (NSUInteger)indexOfPage:(IDBPage *)page;
- (NSUInteger)indexOfCenterPage;

- (IDBPage *)pageAtLocation:(CGPoint)location;

- (CGFloat)widthInSight:(IDBPage *)page;

- (float)floatIndex;
- (NSInteger)index;

- (void)moveToPageAtFloatIndex:(float)index animated:(BOOL)animated;

- (IDBPage *)dequeueReusablePage;
- (void)reloadPages;

@end

@protocol IDBPagingViewDataSource

@required
- (NSUInteger)numberOfPagesInPagingView:(IDBPagingView *)pagingView;
- (IDBPage *)pagingView:(IDBPagingView *)pagingView pageForIndex:(NSUInteger)index;

@end

@protocol IDBPagingViewDelegate

- (void)pagingView:(IDBPagingView *)pagingView didRemovePage:(IDBPage *)page;
- (void)pagingView:(IDBPagingView *)pagingView willMoveToPage:(IDBPage *)page;
- (void)pagingView:(IDBPagingView *)pagingView didMoveToPage:(IDBPage *)page;
- (void)pagingViewLayoutChanged:(IDBPagingView *)pagingView;

@end
