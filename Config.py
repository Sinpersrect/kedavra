import platform

ConfigDict = {
    'CLAUSE_COLOR': 'green',
    'SHOW_REPR': False
}


def setClauseColor(color: str = 'green'):
    ConfigDict['CLAUSE_COLOR'] = color


def getClauseColor():
    return ConfigDict['CLAUSE_COLOR']


def setShowRepr(showRepr: bool):
    ConfigDict['SHOW_REPR'] = showRepr


def getShowRepr():
    return ConfigDict['SHOW_REPR']
