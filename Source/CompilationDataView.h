/*
 * Copyright 2010-2016, BurnItNow Team. All rights reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef _COMPILATIONDATAVIEW_H_
#define _COMPILATIONDATAVIEW_H_


#include "BurnWindow.h"
#include "PathView.h"

#include <Button.h>
#include <FilePanel.h>
#include <Menu.h>
#include <SeparatorView.h>
#include <TextView.h>
#include <View.h>


class CommandThread;


class DataRefFilter : public BRefFilter {
public:
					DataRefFilter() {};
	virtual			~DataRefFilter() {};

	bool			Filter(const entry_ref* ref, BNode* node,
						struct stat_beos* st, const char* filetype);
};


class CompilationDataView : public BView {
public:
					CompilationDataView(BurnWindow& parent);
	virtual 		~CompilationDataView();

	virtual void	MessageReceived(BMessage* message);
	virtual void	AttachedToWindow();
	
	void			BuildISO();
	void			BurnDisc();

private:
	void 			_ChooseDirectory();
	void 			_FromScratch();
	void 			_OpenDirectory(BMessage* message);
	void 			_BurnerOutput(BMessage* message);

	BFilePanel* 	fOpenPanel;
	CommandThread* 	fBurnerThread;
	BTextView* 		fBurnerInfoTextView;
	BurnWindow* 	windowParent;
	BSeparatorView*	fBurnerInfoBox;
	PathView*		fPathView;
	BButton*		fChooseButton;
	BButton*		fImageButton;
	BButton*		fBurnButton;

	BPath* 			fDirPath;
	BPath* 			fImagePath;
	int				step;

};


#endif	// _COMPILATIONDATAVIEW_H_
